#pragma once
#include "../GameObj.hpp"


namespace th {


    class PlayerMovement : public th::Component {

        public:
            PlayerMovement();
            void update(float dt) override;
            void setGameObj(th::GameObj* gameObj) override;

    };
    
} // namespace th
