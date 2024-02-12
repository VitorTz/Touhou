#include "../../include/util/SpriteSheet.hpp"
#include <iostream>



sf::Uint8* th::SpriteSheet::getRawPixelImage(const unsigned int size) {
    sf::Uint8* image = new sf::Uint8[size];
    for (unsigned int i = 0; i < size; ++i) {
        image[i] = 0;
    }
    return image;
}



std::vector<std::unique_ptr<th::Sprite>> th::SpriteSheet::getSprites(
    const std::filesystem::path& file,
    const unsigned int spriteSize
) {
    std::vector<std::unique_ptr<th::Sprite>> sprites;

    sf::Image* spriteImage = new sf::Image();
    spriteImage->loadFromFile(file);
    const sf::Vector2u spriteImageSize = spriteImage->getSize();
    
    std::vector<std::vector<bool>> mk(spriteImageSize.y, std::vector<bool>(spriteImageSize.x, false));
    
    for (unsigned int y = 0; y < spriteImageSize.y; ++y) 
    {
        for (unsigned int x = 0; x < spriteImageSize.x; ++x) 
        {
            if (mk[y][x] == false) 
            {
                mk[y][x] = true;
                sf::Color color = spriteImage->getPixel(x, y);
                if (color.toInteger() != 0) 
                {
                    sf::Uint8* finalPixels = th::SpriteSheet::getRawPixelImage(spriteSize); 
                    std::size_t currentPixelIndex = 0;
                    std::vector<std::pair<unsigned int, unsigned int>> pixels;      
                    pixels.push_back({x, y});

                    while (!pixels.empty()) 
                    {
                        // Extract pixel
                        std::pair<unsigned int, unsigned int> pixel = pixels.back();                        
                        pixels.pop_back();
                        finalPixels[currentPixelIndex++] = spriteImage->getPixel(pixel.first, pixel.second).toInteger();

                        // Mark as visited
                        mk[pixel.second][pixel.first] = true;

                        // Add pixel neighbors
                        unsigned int i, j;

                        // Right
                        i = pixel.first + 1;
                        j = pixel.second;

                        if (
                            i < spriteImageSize.x && 
                            !mk[j][i] &&
                            spriteImage->getPixel(i, j).toInteger() != 0
                        ) {
                            pixels.push_back({i, j});
                        }
                        
                        
                        // Left
                        i -= 2;                        
                        if (
                            i < spriteImageSize.x && 
                            !mk[j][i] &&
                            spriteImage->getPixel(i, j).toInteger() != 0
                        ) {
                            pixels.push_back({i, j});
                        }

                        // Down
                        i += 1;
                        j += 1;

                        if (
                            i < spriteImageSize.x && 
                            !mk[j][i] &&
                            spriteImage->getPixel(i, j).toInteger() != 0
                        ) {
                            pixels.push_back({i, j});
                        }

                        // Top                        
                        j -= 2;

                        if (
                            i < spriteImageSize.x && 
                            !mk[j][i] &&
                            spriteImage->getPixel(i, j).toInteger() != 0
                        ) {
                            pixels.push_back({i, j});
                        }

                    } 

                    
                    sf::Image image;
                    

                }
            }
        }
        delete spriteImage;
    }

    return sprites;
}