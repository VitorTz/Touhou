#include "../../include/util/asset_pool.hpp"
#include <iostream>


std::unordered_map<std::string, th::AssetPool::Asset*> th::AssetPool::assets;

th::AssetPool::Asset* th::AssetPool::getAsset(std::string imagePath) {
    std::filesystem::path p(imagePath);
    if (th::AssetPool::assets.find(p.string()) == th::AssetPool::assets.end()) {
        auto asset = new th::AssetPool::Asset(p.filename(), p.string(), std::filesystem::path(imagePath));
        th::AssetPool::assets.insert({asset->getKey(), asset});
    }
    return th::AssetPool::assets.at(p.string());
}

void th::AssetPool::deleteAssets() {
    for (auto& p : th::AssetPool::assets) {
        delete p.second;
    }
}


th::AssetPool::Asset::Asset(std::string name, std::string key, std::filesystem::path imagePath) {
    this->name = name;
    this->key = key;
    this->loadImage(imagePath);
}

void th::AssetPool::Asset::loadImage(std::filesystem::path imagePath) {    
    if (!this->texture.loadFromFile(imagePath)) {
        exit(EXIT_FAILURE);
    }    
    this->sprite.setTexture(this->texture);
}


void th::AssetPool::Asset::draw(sf::RenderWindow* window, sf::Vector2f& position) {
    this->sprite.setPosition(position);
    window->draw(this->sprite);
}

int th::AssetPool::Asset::width() {
    return this->texture.getSize().x;
}

int th::AssetPool::Asset::height() {
    return this->texture.getSize().y;
}


void th::AssetPool::Asset::draw(sf::RenderWindow* window) {
    window->draw(this->sprite);
}

sf::Sprite* th::AssetPool::Asset::getSprite() {
    return &this->sprite;
}

std::string th::AssetPool::Asset::getKey() {
    return this->key;
}

std::string th::AssetPool::Asset::getName() {
    return this->name;
}
