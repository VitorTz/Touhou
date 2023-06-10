#include "../../include/scene/menu_scene.hpp"
#include "../../include/util/asset_pool.hpp"
#include <iostream>


th::MenuScene::MenuScene(th::Window* touhouWindow) : Scene(touhouWindow, "MenuScene") {
    this->menu.setPos(sf::Vector2f(610, 300));
    this->menu.setSpacing(sf::Vector2f(0, 28));
    this->menu.setAlignment(th::Alignment::Vertical);
    this->menu.addButton(new th::Button(th::ButtonType::MenuButtonStart));
    this->menu.addButton(new th::Button(th::ButtonType::MenuButtonMusicRoom));
    this->menu.addButton(new th::Button(th::ButtonType::MenuButtonConfig));
    this->menu.addButton(new th::Button(th::ButtonType::MenuButtonExit));
    this->addImage(th::MENU_BG_IMG, sf::Vector2f(0, 0));
}


th::MenuScene::~MenuScene() {
    for (auto& imageName : this->menuImages)
        th::AssetPool::deleteAsset(imageName);
}


void th::MenuScene::startGame() {
    this->touhouWindow->changeCurrentScene(th::SceneId::LevelScene);
}


void th::MenuScene::startConfig() {
    std::cout << "Config\n";
}


void th::MenuScene::startMusicRoom() {
    std::cout << "Music\n";
}


void th::MenuScene::exitGame() {
    this->touhouWindow->close();
}


void th::MenuScene::drawImages(sf::RenderWindow* window) {
    for (auto& imageName : this->menuImages)
        th::AssetPool::getAsset(imageName)->draw(window);
}


void th::MenuScene::runMenu() {
    this->menu.run();
    th::Button* clickedButton = this->menu.getClickedButton();
    if (clickedButton != nullptr) {
        switch (clickedButton->getButtonType()) {
            case th::ButtonType::MenuButtonStart:
                this->startGame();
                break;
            case th::ButtonType::MenuButtonMusicRoom:
                this->startMusicRoom();
                break;
            case th::ButtonType::MenuButtonConfig:
                this->startConfig();
                break;
            case th::ButtonType::MenuButtonExit:
                this->exitGame();
                break;
            default:
                break;
        }
    }
}


void th::MenuScene::update(double deltaTime) {
    this->runMenu();
}


void th::MenuScene::draw(sf::RenderWindow* window) {
    this->drawImages(window);
    this->menu.draw(window);
}


void th::MenuScene::addImage(std::string imagePath, sf::Vector2f position) {
    auto* asset = th::AssetPool::getAsset(imagePath);
    asset->getSprite()->setPosition(position);
    this->menuImages.push_back(asset->getKey());
}