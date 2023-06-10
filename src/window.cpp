#include "../include/window.hpp"
#include "../include/util/constants.hpp"
#include "../include/scene/menu_scene.hpp"
#include <iostream>


void th::Window::init() {
    this->changeCurrentScene(0);
}

th::Window::Window() {
    this->window = new sf::RenderWindow(sf::VideoMode(th::SCREEN_WIDTH, th::SCREEN_HEIGHT), th::SCREEN_TITLE, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(th::FPS);
    // set icon
    sf::Image iconImage;
    if (!iconImage.loadFromFile(th::WINDOW_ICON_FILE)) {
        std::cout << "Icone da janela não carregado\n";
        exit(EXIT_FAILURE);
    }
    this->window->setIcon(iconImage.getSize().x, iconImage.getSize().y, iconImage.getPixelsPtr());
    // center window
    sf::VideoMode monitor = sf::VideoMode::getDesktopMode();
    this->window->setPosition(
        sf::Vector2i(monitor.width / 2 - th::SCREEN_WIDTH / 2, monitor.height / 2 - th::SCREEN_HEIGHT / 2)
    );
    this->init();
}

double th::Window::getDeltaTime() {
    sf::Time deltaTime = this->clock.restart();
    return (double) deltaTime.asMilliseconds() / 1000;
}

void th::Window::changeCurrentScene(int sceneId) {
    if (sceneId == 0) {
        this->currentScene = new th::MenuScene();
    }
}


void th::Window::run() {
    while (this->window->isOpen()) {

        sf::Event event;

        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
        }

        this->window->clear(sf::Color::Black);
        double deltaTime = this->getDeltaTime();
        this->currentScene->update(deltaTime);
        this->currentScene->draw(this->window);
        this->window->display();
    }

    th::AssetPool::deleteAssets();

}
