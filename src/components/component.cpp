#ifndef TOUHOU_COMPONENT_CPP
#define TOUHOU_COMPONENT_CPP
#include <SFML/Graphics.hpp>
#include <string>


namespace th {


    class GameObj;

    class Component {

        protected:
            std::string name;
            GameObj* gameObj;
        
        public:
            virtual void update(double deltaTime) {
                return;
            }

            virtual void draw(sf::RenderWindow* window) {
                return;
            }

            void setGameObj(GameObj* gameObj) {
                this->gameObj = gameObj;
            }

            std::string getName() {
                return this->name;
            }


    };

} // namespace th


#endif