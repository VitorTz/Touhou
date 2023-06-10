#pragma once
#ifndef TOUHOU_BUTTON_CPP
#define TOUHOU_BUTTON_CPP
#include <string>
#include "../util/asset_pool.hpp"
#include "../util/constants.hpp"


namespace th {

    enum class ButtonType {
        MenuButton = 0
    };


    class Button {
        
        private:
            th::ButtonType buttonType;
            sf::Vector2f pos;
            bool isActive;
            th::AssetPool::Asset* getButtonAsset();
        public:
            Button(th::ButtonType buttonType);
            void setPos(sf::Vector2f pos);
            int width();
            int height();
            void draw(sf::RenderWindow* window);
            void activate();
            void deactivate();

    };


} // namespace th

#endif