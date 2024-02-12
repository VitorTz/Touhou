#pragma once
#include <algorithm>
#include <vector>
#include "../ecs/Group.hpp"


namespace th {


    class Camera : public th::Group {

        private:
            std::map<int, std::vector<th::GameObj*>> objMap;

        public:
            Camera();
            void insert(th::GameObj* obj) override;
            void erase(th::GameObj* obj) override;     
            void clear() override;
            void draw(sf::RenderWindow& window);

    }; 

} // namespace th

