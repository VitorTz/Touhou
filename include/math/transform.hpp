#pragma once
#include <SFML/Graphics.hpp>


namespace th {


    class Transform {

        public:
            sf::Vector2u dimension;
            sf::Vector2f position;
            sf::Vector2f scale;
            double rotation;
            Transform();
            Transform(float xPos, float yPos);
            Transform(sf::Vector2f position, sf::Vector2f scale, sf::Vector2u dimension, double rotation);


    };

} // namespace th