#pragma once
#include "scene.hpp"



namespace th {

    class LevelScene  : public Scene {

        public:
            LevelScene(th::Window* touhouWindow);
            ~LevelScene() override;
            void update(double deltaTime) override;
            void draw(sf::RenderWindow* window) override;

    };

} // namespace th