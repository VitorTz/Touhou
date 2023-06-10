#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../window.hpp"


namespace th {

    class Window;

    class Scene {

        protected:
            std::string name;
            th::Window* touhouWindow;
        
        public:
            Scene(th::Window* touhouWindow);
            Scene(th::Window* touhouWindow, std::string name);
            virtual ~Scene();
            virtual void update(double deltaTime) = 0;
            virtual void draw(sf::RenderWindow* window) = 0;

    };

} // namespace th