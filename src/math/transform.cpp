#ifndef TOUHOU_TRANSFORM_HPP
#define TOUHOU_TRANSFORM_HPP
#include <SFML/Graphics.hpp>


namespace th {

    class Transform {

        private:
            sf::Vector2f position;
            sf::Vector2f scale;
            double rotation;
        public:
        
            Transform() {
                this->scale.x = 1.;
                this->scale.y = 1.;
                this->rotation = 0;
            }
            Transform(float xPos, float yPos) : Transform() {
                this->position.x = xPos;
                this->position.y = yPos;
            }


    };

} // namespace th



#endif