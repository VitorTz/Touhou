#include "../../include/scene/menu_scene.hpp"
#include "../../include/util/asset_pool.hpp"
#include <iostream>



th::MenuScene::MenuScene() : Scene("MenuScene") {
    this->menu.setPos(sf::Vector2f(610, 300));
    this->menu.setSpacing(sf::Vector2f(0, 28));
    this->menu.addButton(new th::Button(th::ButtonType::MenuButton));
    this->menu.addButton(new th::Button(th::ButtonType::MenuButton));
    this->menu.addButton(new th::Button(th::ButtonType::MenuButton));
    this->menu.addButton(new th::Button(th::ButtonType::MenuButton));
    this->addImage("assets/menu/bg.png", sf::Vector2f(0, 0));
}

void th::MenuScene::update(double deltaTime) {
    this->menu.run();
}

void th::MenuScene::draw(sf::RenderWindow* window) {
    for (auto& image : this->images) {
        image->draw(window);
    }
    this->menu.draw(window);
}

void th::MenuScene::addImage(std::string imagePath, sf::Vector2f position) {
    auto* asset = th::AssetPool::getAsset(imagePath);
    asset->getSprite()->setPosition(position);
    this->images.push_back(asset);
}