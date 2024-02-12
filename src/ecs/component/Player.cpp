#include "../../../include/ecs/component/Player.hpp"


th::Player::Player(

) : th::Component("Player") {
    // animation(th::characterDirMap.at(th::globals::currentCharacter)) {
    // for (auto& [name, animation] : *animation.getAnimationMap()) {
    //     animation.setRepeat(false);
    // }
    std::vector<std::unique_ptr<th::Sprite>> a = th::SpriteSheet::getSprites(
        "res/Characters/Reimu/ReimuHakurei.png", {30, 48}
    );
}


void th::Player::handleAnimation() {
    // switch (gameObj->directionState) {        
    //     case th::GameObjState::Left:
    //         animation.changeAnimation("left");
    //         break;
    //     case th::GameObjState::Right:
    //         animation.changeAnimation("right");
    //         break;
    //     case th::GameObjState::Idle:
    //         animation.changeAnimation("idle");
    //         break;
    //     default:
    //         break;
    // }
}


void th::Player::update(const float dt) {    
    movement.update(dt);
    attack.update(dt);
    // handleAnimation();
    // animation.update(dt);    
}


void th::Player::draw(sf::RenderWindow& window) {
    // animation.draw(window);
}


void th::Player::setGameObj(th::GameObj* gameObj) {
    th::Component::setGameObj(gameObj);
    // animation.setGameObj(gameObj);
    movement.setGameObj(gameObj);
    attack.setGameObj(gameObj);
}