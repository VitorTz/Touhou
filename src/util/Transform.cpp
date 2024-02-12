#include "../../include/util/Transform.hpp"


th::Transform::Transform(
    const sf::Vector2f pos,
    const sf::Vector2f size,
    const sf::Vector2f boxCollideScale,
    const sf::Vector2f direction,
    const sf::Vector2f scale,
    const float rotation,
    const float speed
) : pos(pos),
    size(size),
    boxCollideScale(boxCollideScale),
    direction(direction),
    scale(scale),
    rotation(rotation),
    speed(speed) {

}


float th::Transform::left() const {
    return pos.x;
}

float th::Transform::bottom() const {
    return pos.y + size.y;
}


float th::Transform::right() const {
    return pos.x + size.x;
}


float th::Transform::top() const {
    return pos.y;
}


void th::Transform::setLeft(const float left) {
    pos.x = left;
}


void th::Transform::setTop(const float top) {
    pos.y = top;
}


void th::Transform::setRight(const float right) {
    pos.x = right - size.x;
}


void th::Transform::setBottom(const float bottom) {
    pos.y = bottom - size.y;
}


float th::Transform::width() const {
    return size.x;
}


float th::Transform::height() const {
    return size.y;
}


void th::Transform::setWidth(const float width) {
    size.x = width;
}


void th::Transform::setHeight(const float height) {
    size.y = height;
}


float th::Transform::centerX() const {
    return pos.x + size.x / 2;
}


float th::Transform::centerY() const {
    return pos.y + size.y / 2;
}


void th::Transform::setCenterX(const float centerX) {
    pos.x = centerX - size.x / 2;
}


void th::Transform::setCenterY(const float centerY) {
    pos.y = centerY - size.y / 2;
}


sf::Vector2f th::Transform::center() const {
    return {
        pos.x + size.x / 2,
        pos.y + size.y / 2
    };
}


void th::Transform::setCenter(const sf::Vector2f center) {
    pos.x = center.x - size.x / 2;
    pos.y = center.y - size.y / 2;
}


void th::Transform::move(const float dt) {
    pos.x += dt * speed * direction.x;
    pos.y += dt * speed * direction.y;
}


void th::Transform::move(const sf::Vector2f distance) {
    pos += distance;
}


bool th::Transform::collide(const th::Transform& t) const {
    return (
        t.right() < size.x || 
        t.left() > right() || 
        t.bottom() < size.y ||
        t.top() > bottom()
    );
}


bool th::Transform::collideWithShrink(th::Transform& t) {
    const sf::Vector2f oldSizeThis = size;
    const sf::Vector2f oldSizeOther = t.size;

    size.x *= boxCollideScale.x;
    size.y *= boxCollideScale.y;
    t.size.x *= t.boxCollideScale.x;
    t.size.y *= t.boxCollideScale.y;

    bool collide = (
        t.right() < size.x || 
        t.left() > right() || 
        t.bottom() < size.y ||
        t.top() > bottom()
    );

    size = oldSizeThis;
    t.size = oldSizeOther;

    return collide;

}