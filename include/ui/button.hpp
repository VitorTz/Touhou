#pragma once
#ifndef TOUHOU_BUTTON_CPP
#define TOUHOU_BUTTON_CPP
#include <string>
#include "../util/asset_pool.hpp"
#include "../util/constants.hpp"


namespace th {

    enum class ButtonType {
        MenuButtonStart = 0,
        MenuButtonMusicRoom = 1,
        MenuButtonConfig = 2,
        MenuButtonExit = 3
    };


    class Button {
        
        private:
            th::AssetPool::Asset* getButtonAsset();
            th::ButtonType buttonType;
            sf::Vector2f pos;
            bool isActive;
        public:
            Button(th::ButtonType buttonType);
            void draw(sf::RenderWindow* window);
            void activate();
            void deactivate();
            int width();
            int height();
            void setPos(sf::Vector2f pos);
            th::ButtonType getButtonType();
    };


} // namespace th

#endif