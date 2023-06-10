#pragma once
#include "button.hpp"
#include "../util/alignment.hpp"
#include <vector>


namespace th {

    class Menu {

        private:
            
            std::vector<th::Button*> buttons;
            sf::Vector2f pos;
            sf::Vector2f spacing;
            th::Button* clickedButton;
            int currentActiveButton;
            th::Alignment alignment;
            void handleActiveButtonChange();
            void handleButtonClick();
        
        public:
            Menu();
            Menu(sf::Vector2f pos, sf::Vector2f spacing, th::Alignment alignment);
            ~Menu();
            void setPos(sf::Vector2f pos);
            void setSpacing(sf::Vector2f spacing);
            void setAlignment(th::Alignment alignment);
            void addButton(th::Button* button);
            void draw(sf::RenderWindow* window);
            bool isButtonClicked();
            bool hasButtons();
            void run();
            th::Button* getClickedButton();

    };

} // namespace th