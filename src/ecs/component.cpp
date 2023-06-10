#include "../../include/ecs/component.hpp"


th::Component::Component(std::string name) {
    this->name = name;
}

th::Component::~Component() {

}

void th::Component::setGameObj(th::GameObj* gameObj) {
    this->gameObj = gameObj;
}

std::string th::Component::getName() {
    return this->name;
}

