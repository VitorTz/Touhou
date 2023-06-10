#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>


namespace th {

    class Component;

    class GameObj {

        private:
            std::string name;
            std::unordered_map<std::string, th::Component*> components;
        public:
            GameObj(std::string name);
            ~GameObj();
            void update(double deltaTime);
            void draw(sf::RenderWindow* window);
            void addComponent(th::Component* component);
            th::Component* getComponent(std::string componentName);

    };

} // namespace th