#include "../../../include/ecs/component/Sprite.hpp"
#include <iostream>


th::Sprite::Sprite(
    const std::filesystem::path& source
) : th::Component("Sprite-" + source.string()),
    source(source) {
        th::TexturePool::load(&sprite, source);
    }


th::Sprite::~Sprite() {
    th::TexturePool::erase(source);
}


void th::Sprite::draw(sf::RenderWindow& window) {
    sprite.setPosition(gameObj->transform.pos);
    sprite.setScale(gameObj->transform.scale);
    sprite.setRotation(gameObj->transform.rotation);
    window.draw(sprite);
}


void th::Sprite::setGameObj(th::GameObj* gameObj) {
    th::Component::setGameObj(gameObj);
    gameObj->transform.size = (sf::Vector2f) sprite.getTexture()->getSize();
}