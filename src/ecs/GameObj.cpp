#include "../../include/ecs/GameObj.hpp"


th::GameObj::GameObj(
    std::string name_,
    const int zIndex_ = 0
) : name(std::move(name_)),
    zIndex(zIndex_) {

}



void th::GameObj::update(const float dt) {
    for (const auto& [name, component] : componentMap) {
        component->update(dt);
    }
}


void th::GameObj::draw(sf::RenderWindow& window) {
    for (const auto& [name, component] : componentMap) {
        component->draw(window);
    }
}



void th::GameObj::addComponent(std::unique_ptr<th::Component> c) {
    c->setGameObj(this);
    componentMap.insert({c->name, std::move(c)});
}


th::Component* th::GameObj::getComponent(const std::string& name) {
    return componentMap.at(name).get();
}