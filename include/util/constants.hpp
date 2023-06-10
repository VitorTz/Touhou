#pragma once
#include <string>


namespace th {

    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 700;
    const std::string SCREEN_TITLE = "Touhou";
    const int FPS = 120;
    const std::string WINDOW_ICON_FILE = "assets/icons/reimu-icon.png";
    
    const std::pair<std::string, std::string> buttonInfoByNumber[] = {
        {"assets/menu/startBtnActive.png", "assets/menu/startBtnInactive.png"},
        {"assets/menu/musicBtnActive.png", "assets/menu/musicBtnInactive.png"},
        {"assets/menu/configBtnActive.png", "assets/menu/configBtnInactive.png"},
        {"assets/menu/exitBtnActive.png", "assets/menu/exitBtnInactive.png"}
    };

    enum class SceneId{
        MenuScene,
        LevelScene
    };

    enum class ButtonType {
        MenuButtonStart = 0,
        MenuButtonMusicRoom = 1,
        MenuButtonConfig = 2,
        MenuButtonExit = 3
    };

    const std::string MENU_BG_IMG = "assets/menu/bg.png";
    
} // namespace th
