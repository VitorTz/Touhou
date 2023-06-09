#ifndef TOUHOU_GAMEOBJ_CPP
#define TOUHOU_GAMEOBJ_CPP
#include "components/component.cpp"
#include "math/transform.cpp"
#include <unordered_map>

namespace th {

    class GameObj {

        private:
            std::unordered_map<std::string, Component*> components;
            th::Transform transform;
            std::string name;
        
        public:
            GameObj(std::string name, th::Transform transform) {
                this->name = name;
                this->transform = transform;    
            }

            void addComponent(th::Component* component) {
                this->components[component->getName()] = component;
                component->setGameObj(this);
            }

            th::Component* getComponent(std::string componentName) {
                return this->components.at(componentName);
            }

            void update(double deltaTime) {
                for (auto& pair : this->components) {
                    pair.second->update(deltaTime);
                }
            }

            void draw(sf::RenderWindow* window) {
                for (auto& pair : this->components) {
                    pair.second->draw(window);
                }
            }

            th::Transform& getTransform() {
                return this->transform;
            }

            std::string getName() {
                return this->name;
            }

    };


} // namespace th


#endif