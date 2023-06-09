#ifndef TOUHOU_MENU_SCENE_CPP
#define TOUGOU_MENU_SCENE_CPP
#include "scene.cpp"


namespace th {

    class MenuScene : public Scene {

        public:
        
            MenuScene() : Scene("Menu") {
                th::GameObj* gameObj = new th::GameObj("Player", th::Transform(100., 100.));
            }

            void update(double deltaTime) override {
                return;
            }

            void draw(sf::RenderWindow* window) override {
                return;
            }

    };

}

#endif