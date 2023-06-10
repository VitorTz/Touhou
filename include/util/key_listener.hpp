#pragma once
#include <SFML/Graphics.hpp>


namespace th {

    class KeyListener {

        private:
            static bool keys[128];
        public:
            static bool isKeyPressed(sf::Keyboard::Key k);
    };

} // namespace th