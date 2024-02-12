#pragma once
#include "../GameObj.hpp"
#include "../../util/Timer.hpp"


namespace th {


    class PlayerAttack : public th::Component {

    
        public:
            PlayerAttack();
            void update(float dt) override;            
        
    };

    
} // namespace th
