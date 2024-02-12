#pragma once
#include "../GameObj.hpp"
#include "Sprite.hpp"
#include <filesystem>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>


namespace th {

    
    const double ANIMATION_SPEED = 7.f;


    class Animation : public th::Component {

        private:
            std::vector<std::unique_ptr<th::Sprite>> sprites;
            bool repeat;
            double animationSpeed;
            double currentIndex = 0;

        public:
            Animation(
                const std::string& name,
                const std::filesystem::path& source,
                bool repeat,
                double animationSpeed
            );
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(th::GameObj* gameObj) override;
            void setRepeat(bool repeatOn);
            void reset();
            
    };

    
    class AnimationPool : public th::Component {

        private:
            std::map<std::string, th::Animation> animationMap;
            std::string animationName;

        public:
            AnimationPool(
                const std::filesystem::path& source
            );
            void changeAnimation(const std::string& animationName);
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override; 
            void setGameObj(th::GameObj* gameObj) override;
            std::map<std::string, th::Animation>* getAnimationMap();
    };
    
    
} // namespace th
