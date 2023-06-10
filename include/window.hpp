#pragma once
#include <SFML/Graphics.hpp>
#include "scene/scene.hpp"
#include "util/constants.hpp"


namespace th {

    class Scene;

    class Window {

        private:
            
            sf::RenderWindow* window;
            sf::Clock clock;
            th::Scene* currentScene;
            double getDeltaTime();
            void run();
        public:
            Window();
            void changeCurrentScene(th::SceneId sceneId);
            void close();
    };

} // namespace th