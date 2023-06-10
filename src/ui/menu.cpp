#include "../../include/ui/menu.hpp"
#include "../../include/util/key_listener.hpp"
#include <iostream>


th::Menu::Menu() {
    this->clickedButton = nullptr;
    this->alignment = th::Alignment::Vertical;
    this->currentActiveButton = -1;
}


th::Menu::Menu(sf::Vector2f pos, sf::Vector2f spacing, th::Alignment alignment) {
    this->pos = pos;
    this->spacing = spacing;
    this->alignment = alignment;
    this->clickedButton = nullptr;
}

th::Menu::~Menu() {
    for (th::Button* b : this->buttons) {
        delete b;
    }
}

void th::Menu::addButton(th::Button* button) {
    // New button pos
    int numBtns = this->buttons.size();
    float left = this->pos.x;
    float top = this->pos.y;
    if (this->alignment == th::Alignment::Vertical) 
        top += (numBtns * button->height()) + (numBtns * this->spacing.y);
    else if (this->alignment == th::Alignment::Horizontal) 
        left += (numBtns * button->width()) + (numBtns * this->spacing.x);
    button->setPos(sf::Vector2f(left, top));
    // Add new button
    this->buttons.push_back(button);
    if (this->buttons.size() == 1) this->currentActiveButton = 0;
    
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

void th::Menu::setAlignment(th::Alignment alignment) {
    this->alignment = alignment;
}


bool th::Menu::isButtonClicked() {
    return this->clickedButton != nullptr;
}

th::Button* th::Menu::getClickedButton() {
    return this->clickedButton;
}

bool th::Menu::hasButtons() {
    return this->buttons.size() > 0;
}

void th::Menu::handleActiveButtonChange() {
    if (this->hasButtons()) {
        int delta = 0;
        if (th::KeyListener::isKeyPressed(sf::Keyboard::Up)) delta = -1;
        else if (th::KeyListener::isKeyPressed(sf::Keyboard::Down)) delta = 1;
        this->buttons[this->currentActiveButton]->deactivate();
        this->currentActiveButton = (this->currentActiveButton + delta) % this->buttons.size();
        this->buttons[this->currentActiveButton]->activate();
    }
}

void th::Menu::handleButtonClick() {
    this->clickedButton = nullptr;
    if (this->hasButtons() && th::KeyListener::isKeyPressed(sf::Keyboard::Enter)) {
        this->clickedButton = this->buttons[this->currentActiveButton];
    }
}

void th::Menu::run() {
    this->handleActiveButtonChange();
    this->handleButtonClick();
}