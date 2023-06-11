#include "touhou.hpp"


namespace th {


    class Image {

        private:
            sf::Texture* texture;
            sf::Sprite* sprite;
            Image(th::ImageId imageId);
            static std::unordered_map<th::ImageId, th::Image*> images;

        public:
            static th::Image* getImage(th::ImageId imageId);
            static void deleteImage(th::ImageId imageId);
            sf::Texture* getTexture();
            sf::Sprite* getSprite();
            void draw(sf::RenderWindow* window);
    };


} // namespace th