#include "../../../include/ecs/component/PlayerMovement.hpp"


th::PlayerMovement::PlayerMovement(

) : th::Component("PlayerMovement") {

}


void th::PlayerMovement::update(const float dt) {
    gameObj->directionState = th::GameObjState::Idle;
    
    sf::Vector2f* direction = &gameObj->transform.direction;
    *direction = sf::Vector2f();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        direction->y = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {        
        direction->y = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        gameObj->directionState = th::GameObjState::Left;
        direction->x = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        gameObj->directionState = th::GameObjState::Right;
        direction->x = 1;
    }
    
    th::normalizeVector(*direction);    
    gameObj->transform.move(dt);
}


void th::PlayerMovement::setGameObj(th::GameObj* gameObj) {
    th::Component::setGameObj(gameObj);
    gameObj->transform.speed = th::PLAYER_SPEED;
}