#include "../../include/util/key_listener.hpp"
#include <SFML/Graphics.hpp>

bool th::KeyListener::keys[128];


bool th::KeyListener::isKeyPressed(sf::Keyboard::Key k) {
    int code = (int) k;
    if (sf::Keyboard::isKeyPressed(k) && !th::KeyListener::keys[code])  {
        th::KeyListener::keys[code] = true;
        return true;
    } else if (!sf::Keyboard::isKeyPressed(k)) {
        th::KeyListener::keys[code] = false;
    } 
    return false;
}
