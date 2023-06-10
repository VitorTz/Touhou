#pragma once
#include "scene.hpp"
#include "../util/asset_pool.hpp"
#include "../ui/button.hpp"
#include "../ui/menu.hpp"
#include <vector>


namespace th {


    class MenuScene : public Scene {

        private:
            std::vector<th::AssetPool::Asset*> images;
            th::Menu menu;
            void drawImages(sf::RenderWindow* window);
            void startGame();
            void startConfig();
            void startMusicRoom();
            void exitGame();
            void runMenu();
            
        public:
            MenuScene(th::Window* touhouWindow);
            ~MenuScene() override;
            void update(double deltaTime) override;
            void draw(sf::RenderWindow* window) override;
            void addImage(std::string imagePath, sf::Vector2f position);

    };

} // namespace th