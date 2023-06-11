#include "../include/touhou.hpp"


th::TouhouWindow::TouhouWindow() {
    
    this->window = new sf::RenderWindow(
        sf::VideoMode(th::SCREEN_WIDTH, th::SCREEN_HEIGHT),
        th::SCREEN_TITLE,
        sf::Style::Titlebar | sf::Style::Close
    );
    this->window->setFramerateLimit(th::FPS);
    
    auto monitorSize = sf::VideoMode::getDesktopMode();
    this->window->setPosition(
        sf::Vector2i(
            monitorSize.width / 2 - th::SCREEN_WIDTH / 2,
            monitorSize.height / 2 - th::SCREEN_HEIGHT / 2
        )
    );

    sf::Image iconImage;
    if (!iconImage.loadFromFile(th::imagePathById.at(th::ImageId::REIMU_ICON))) {
        std::cout << "Icon não pode ser carregado!\n";
        exit(EXIT_FAILURE);
    }    
    this->window->setIcon(iconImage.getSize().x, iconImage.getSize().y, iconImage.getPixelsPtr());
    this->mainloop();
}

void th::TouhouWindow::mainloop() {
    while (this->window->isOpen()) {

        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
        }
        
        th::Image* image = th::Image::getImage(th::ImageId::MENU_BG);
        this->window->clear();
        image->draw(this->window);
        this->window->display();
    }
}

void th::TouhouWindow::close() {
    this->window->close();
}