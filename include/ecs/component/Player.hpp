#pragma once
#include "Animation.hpp"
#include "PlayerMovement.hpp"
#include "PlayerAttack.hpp"
#include "../../util/SpriteSheet.hpp"


namespace th {


    class Player : public th::Component {

        private:            
            // th::AnimationPool animation;
            th::PlayerMovement movement;
            th::PlayerAttack attack;
            void handleAnimation();

        public:
            Player();
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(th::GameObj* gameObj) override;

    };

    
} // namespace th
