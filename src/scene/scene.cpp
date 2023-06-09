#ifndef TOUHOU_SCENE_CPP
#define TOUHOU_SCENE_CPP
#include <unordered_set>
#include "../game_obj.cpp"
#include <string>


namespace th {

    class Scene {

        protected:
            std::string name;
            std::unordered_set<th::GameObj*> gameObjs;
        
        public:

            Scene(std::string name) {
                this->name = name;
            }
            
            virtual void update(double deltaTime) {
                for (auto& g : this->gameObjs) {
                    g->update(deltaTime);
                }
            }

            virtual void draw(sf::RenderWindow* window) {
                for (auto& g : this->gameObjs) {
                    g->draw(window);
                }
            }

            void addGameObj(th::GameObj* gameObj) {
                this->gameObjs.insert(gameObj);
            }

            std::string getName() {
                return this->name;
            }

    };

}

#endif