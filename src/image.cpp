#include "../include/touhou.hpp"


std::unordered_map<th::ImageId, th::Image*> th::Image::images;


th::Image::Image(th::ImageId imageId) {
    this->texture = new sf::Texture;
    this->sprite = new sf::Sprite;
    this->texture->loadFromFile(th::imagePathById.at(imageId));
    this->sprite->setTexture(*this->texture);
    std::cout << "New image created\n";
}

th::Image* th::Image::getImage(th::ImageId imageId) {
    if (th::Image::images.find(imageId) == th::Image::images.end()) {
        th::Image::images.insert({imageId, new th::Image(imageId)});
    }
    return th::Image::images.at(imageId);
}

void th::Image::deleteImage(th::ImageId ImageId) {
    auto it = th::Image::images.find(ImageId);
    if (it != nullptr) {
        th::Image* image = th::Image::images.at(ImageId);
        th::Image::images.erase(it);
        delete image;
        image = nullptr;
    }
    std::cout << th::Image::images.size() << '\n';
}

sf::Texture* th::Image::getTexture() {
    return this->texture;
}

sf::Sprite* th::Image::getSprite() {
    return this->sprite;
}

void th::Image::draw(sf::RenderWindow* window) {
    window->draw(*this->sprite);
}