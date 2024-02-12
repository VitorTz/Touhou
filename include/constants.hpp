#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <map>
#include <filesystem>
#include <string>
#include "util/Characters.hpp"


namespace th {


    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 700;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const std::string SCREEN_TITLE("Touhou");
    const sf::Color SCREEN_COLOR(0, 0, 0);
    const int FPS = 60;    

    const float PLAYER_SPEED = 250.f;

    // Characters
    const std::map<th::Characters, std::filesystem::path> characterDirMap = {
        {th::Characters::ReimuHakurei, "res/Characters/ReimuHakurei.png"},
        {th::Characters::MarisaKirisame, "res/Characters/MarisaKirisame.png"}
    };
    
} // namespace th
