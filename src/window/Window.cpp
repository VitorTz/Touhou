#include "../../include/window/Window.hpp"


th::Window::Window(

) : window(
    sf::VideoMode(th::SCREEN_WIDTH, th::SCREEN_HEIGHT),
    th::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    window.setFramerateLimit(th::FPS);
    
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - th::SCREEN_WIDTH / 2,
            desktop.height / 2 - th::SCREEN_HEIGHT / 2
        )
    );

    changeScene = [this](const th::SceneId id) {
        switch (id) {
            case th::SceneId::LevelScene:
                scene = std::make_unique<th::Level>(this->changeScene);
                break;
            default:
                break;
        }
    };
    
    initGame();

}


th::Window::~Window() {
    th::Ecs::groupPool->clear();
    th::Ecs::gameObjPool->clear();
}


void th::Window::initGame() {
    changeScene(th::mainScene);
}


void th::Window::handleEvents() {
    sf::Event e;

    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}


void th::Window::update() {
    const float dt = clock.restart().asSeconds();
    scene->update(dt);
}


void th::Window::render() {
    window.clear(th::SCREEN_COLOR);
    scene->draw(window);
    window.display();
}


void th::Window::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}