#include "../../include/util/TexturePool.hpp"


th::TextureMap th::TexturePool::textureMap;


sf::Texture* th::TexturePool::get(const std::filesystem::path& source) {
    if (th::TexturePool::textureMap.find(source) == th::TexturePool::textureMap.end()) {
        const auto& [pair, success] = th::TexturePool::textureMap.insert(
            {source, std::make_unique<sf::Texture>()}
        );
        pair->second->setSmooth(true);
        pair->second->loadFromFile(source);
    }
    return th::TexturePool::textureMap.at(source).get();
}


void th::TexturePool::load(sf::Sprite* sprite, const std::filesystem::path& source) {
    sprite->setTexture(*th::TexturePool::get(source));
}


void th::TexturePool::erase(const std::filesystem::path& source) {
    th::TexturePool::textureMap.erase(source);
}