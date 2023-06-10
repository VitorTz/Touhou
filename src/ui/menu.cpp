#include "../../include/ui/menu.hpp"


th::Menu::Menu() {
    this->clickedButton = nullptr;
}


th::Menu::Menu(sf::Vector2f pos, sf::Vector2f spacing) {
    this->pos = pos;
    this->spacing = spacing;
    this->clickedButton = nullptr;
}

th::Menu::~Menu() {
    for (th::Button* b : this->buttons) {
        delete b;
    }
}

void th::Menu::addButton(th::Button* button) {
    int d = this->buttons.size();
    float left = this->pos.x + d * (button->width() + this->spacing.x);
    float top = this->pos.y + this->buttons.size() * this->spacing.y;
    button->setPos(sf::Vector2f(left, top));
    this->buttons.push_back(button);
}

void th::Menu::draw(sf::RenderWindow* window) {
    for (th::Button* b : this->buttons) {
        b->draw(window);
    }
}

void th::Menu::setPos(sf::Vector2f pos) {
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}

void th::Menu::setSpacing(sf::Vector2f spacing) {
    this->spacing.x = spacing.x;
    this->spacing.y = spacing.y;
}


bool th::Menu::isButtonClicked() {
    return this->clickedButton != nullptr;
}

th::Button* th::Menu::getClickedButton() {
    return this->clickedButton;
}

void th::Menu::run() {

}