#pragma once
#include <string>
#include "game_obj.hpp"


namespace th {

    class Component {

        protected:
            std::string name;
            th::GameObj* gameObj;
        public:
            Component(std::string name);
            virtual ~Component();
            virtual void update(double deltaTime) = 0;
            virtual void draw(sf::RenderWindow* window) = 0;
            virtual void setGameObj(th::GameObj* gameObj);
            std::string getName();
    };

} // namespace th