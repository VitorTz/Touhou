#ifndef TOUHOU_CONSTANTS_HPP
#define TOUHOU_CONSTANTS_HPP
#include <string>
#include <unordered_map>


namespace th {

    // Window
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 700;
    const std::string SCREEN_TITLE = "Touhou";
    const int FPS = 120;
    

    // Images

    enum class ImageId {

        // Icons
        REIMU_ICON,
        // Menu
        MENU_BG

    };

    const std::unordered_map<th::ImageId, std::string> imagePathById = {
        {th::ImageId::REIMU_ICON, "assets/icons/reimu-icon.png"},
        {th::ImageId::MENU_BG, "assets/menu/bg.png"}
    };

}


#endif // TOUHOU_CONSTANTS_HPP