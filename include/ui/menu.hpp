#pragma once
#include "button.hpp"
#include <vector>


namespace th {

    class Menu {

        private:
            
            std::vector<th::Button*> buttons;
            sf::Vector2f pos;
            sf::Vector2f spacing;
            th::Button* clickedButton;
        
        public:
            Menu();
            Menu(sf::Vector2f pos, sf::Vector2f spacing);
            ~Menu();
            void setPos(sf::Vector2f pos);
            void setSpacing(sf::Vector2f spacing);
            void addButton(th::Button* button);
            void draw(sf::RenderWindow* window);
            bool isButtonClicked();
            void run();
            th::Button* getClickedButton();

    };

} // namespace th