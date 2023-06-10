#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <filesystem>


namespace th {

    class AssetPool {

        public:

            class Asset {
                
                private:
                    std::string name;
                    std::string key;
                    sf::Texture texture;
                    sf::Sprite sprite;
                    void loadImage(std::filesystem::path imagePath);

                public:
                    Asset(std::string name, std::string key, std::filesystem::path imagePath);
                    void draw(sf::RenderWindow* window, sf::Vector2f& position);
                    void draw(sf::RenderWindow* window);
                    int width();
                    int height();
                    sf::Sprite* getSprite();
                    std::string getName();
                    std::string getKey();
            };

            static th::AssetPool::Asset* getAsset(std::string imagePath);
            static void deleteAsset(std::string assetName);
            static void deleteAssets();
            static int size();

        private:

            static std::unordered_map<std::string, Asset*> assets;

    };


} // namesapce th