#include "../../include/ecs/game_obj.hpp"
#include "../../include/ecs/component.hpp"


th::GameObj::GameObj(std::string name) {
    this->name = name;
}

th::GameObj::~GameObj() {
    for (auto& p : this->components) {
        delete p.second;
    }
}

void th::GameObj::update(double deltaTime) {
    for (auto& p : this->components) {
        p.second->update(deltaTime);
    }
}

void th::GameObj::draw(sf::RenderWindow* window) {
    for (auto& p : this->components) {
        p.second->draw(window);
    }
}

void th::GameObj::addComponent(th::Component* component) {
    this->components.insert({component->getName(), component});
}

th::Component* th::GameObj::getComponent(std::string componentName) {
    return this->components.at(componentName);
}