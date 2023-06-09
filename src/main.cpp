#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "scene/scene.cpp"
#include "scene/menu_scene.cpp"


class Window {


    private:
        sf::RenderWindow* window;
        sf::Clock clock;
        th::Scene* currentScene;
        
        void init() {
            this->currentScene = new th::MenuScene();
        }

        double getDeltaTime() {
            sf::Time deltaTime = this->clock.restart();
            return (double) deltaTime.asMilliseconds() / 1000;
        }

    public:

        Window() {
            this->window = new sf::RenderWindow(sf::VideoMode(th::SCREEN_WIDTH, th::SCREEN_HEIGHT), th::SCREEN_TITLE);
            this->window->setFramerateLimit(th::FPS);
            // Icon
            sf::Image icon;
            if (!icon.loadFromFile(th::ICON_FILE)) {
                std::cout << "Icon não pode ser carregado\n";
                exit(EXIT_FAILURE);
            }
            this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
            this->init();
        }

        void run() {
            while (this->window->isOpen()) {
                sf::Event event;
            
                while (this->window->pollEvent(event))
                    if (event.type == sf::Event::Closed)
                        this->window->close();

                this->window->clear(sf::Color::Black);
                double deltaTime = this->getDeltaTime();
                std::cout << deltaTime << '\n';
                this->currentScene->update(deltaTime);
                this->currentScene->draw(this->window);
                this->window->display();
            }
        }

};



int main() {
    Window w;
    w.run();
    return 0;
}