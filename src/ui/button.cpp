#include "../../include/ui/button.hpp"


th::Button::Button(th::ButtonType buttonType) {
    this->isActive = false;
    this->buttonType = buttonType;
}

th::Button::~Button() {
    std::pair<std::string, std::string> images = th::buttonInfoByNumber[ (int) this->buttonType];
    std::filesystem::path k1(images.first);
    std::filesystem::path k2(images.second);
    th::AssetPool::deleteAsset(k1.string());
    th::AssetPool::deleteAsset(k2.string());
}


th::AssetPool::Asset* th::Button::getButtonAsset() {
    std::pair<std::string, std::string> images = th::buttonInfoByNumber[ (int) this->buttonType];
    std::string imagePath = this->isActive ? images.first : images.second;
    return th::AssetPool::getAsset(imagePath);
}

void th::Button::draw(sf::RenderWindow* window) {
    th::AssetPool::Asset* asset = this->getButtonAsset();
    asset->getSprite()->setPosition(this->pos);
    asset->draw(window);
}

int th::Button::width() {
    return this->getButtonAsset()->width();
}

int th::Button::height() {
    return this->getButtonAsset()->height();
}

void th::Button::setPos(sf::Vector2f pos) {
    this->pos = pos;
}

th::ButtonType th::Button::getButtonType() {
    return this->buttonType;
}


void th::Button::activate() {
    this->isActive = true;
}

void th::Button::deactivate() {
    this->isActive = false;
}