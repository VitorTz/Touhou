#pragma once
#include <SFML/Graphics.hpp>
#include "../include/scene/scene.hpp"


namespace th {

    class Window {

        private:
            
            sf::RenderWindow* window;
            sf::Clock clock;
            th::Scene* currentScene;
            void init();
            void changeCurrentScene(int sceneId);
            double getDeltaTime();
        public:

            Window();
            void run();
    };

} // namespace th