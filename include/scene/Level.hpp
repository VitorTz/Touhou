#pragma once
#include "Scene.hpp"


namespace th {

    class Level : public Scene {

        public:
            Level(const th::ChangeScene& changeScene);
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace th
