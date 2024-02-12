#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../constants.hpp"
#include "../scene/scenes.hpp"

namespace th {


    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            std::unique_ptr<th::Scene> scene;
            th::ChangeScene changeScene;
        
        private:
            void initGame();
            void handleEvents();
            void update();
            void render();
        
        public:
            Window();
            ~Window();
            void run();

    };
    
} // namespace th
