#pragma once
#include <SFML/Graphics.hpp>
#include "../include/scene/scene.hpp"


namespace th {

    class Scene;

    class Window {

        private:
            
            sf::RenderWindow* window;
            sf::Clock clock;
            th::Scene* currentScene;
            void init();
            double getDeltaTime();
        public:
            Window();
            void changeCurrentScene(int sceneId);
            void close();
            void run();
    };

} // namespace th