#include "touhou.hpp"



namespace th {

    class TouhouWindow {

        private:
            sf::RenderWindow* window;
            sf::Clock clock;
            void mainloop();

        public:
            TouhouWindow();
            void close();

    };

} //namespace th