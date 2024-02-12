#pragma once
#include <filesystem>
#include "../Ecs.hpp"
#include "../../util/TexturePool.hpp"


namespace th {

    class Sprite : public th::Component {

        private:
            const std::filesystem::path source;
            sf::Sprite sprite;

        public:
            Sprite(const std::filesystem::path& source);
            ~Sprite() override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(th::GameObj* gameObj) override;

    };
    
} // namespace th
