#include "../../include/math/transform.hpp"


th::Transform::Transform() {
    this->scale.x = 1.;
    this->scale.y = 1.;
    this->rotation = 0;
}

th::Transform::Transform(float xPos, float yPos) : Transform() {
    this->position.x = xPos;
    this->position.y = yPos;
}

th::Transform::Transform(sf::Vector2f position, sf::Vector2f scale, sf::Vector2u dimension, double rotation) : Transform(position.x, position.y) {
    this->scale.x = scale.x;
    this->scale.y = scale.y;
    this->rotation = rotation;
    this->dimension.x = dimension.x;
    this->dimension.y = dimension.y;
}