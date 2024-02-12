#pragma once
#include "../ecs/component/Sprite.hpp"
#include "TexturePool.hpp"


namespace th {

    typedef struct SpriteSheetImage {
        std::vector<std::pair<unsigned int, unsigned int>> pixels;
        int width;
        int height;
    } SpriteSheetImage;

    class SpriteSheet {

        private:
            static sf::Uint8* getRawPixelImage(const unsigned int size);

        public:
            static std::vector<std::unique_ptr<th::Sprite>> getSprites(
                const std::filesystem::path& file,
                unsigned int spriteSize
            );

    };
    
} // namespace th
