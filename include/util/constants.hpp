#pragma once
#include <string>


namespace th {

    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 700;
    const std::string SCREEN_TITLE = "Touhou";
    const int FPS = 120;
    const std::string WINDOW_ICON_FILE = "assets/icons/reimu-icon.png";
    const std::pair<std::string, std::string> buttonInfoByNumber[] = {
        {"assets/menu/activeButton.png", "assets/menu/inactiveButton.png"}
    };
} // namespace th
