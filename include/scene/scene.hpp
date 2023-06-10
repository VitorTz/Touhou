#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace th {

    class Scene {

        protected:
            std::string name;
        
        public:
            Scene();
            Scene(std::string name);
            virtual void update(double deltaTime) = 0;
            virtual void draw(sf::RenderWindow* window) = 0;

    };

} // namespace th