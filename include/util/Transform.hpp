#pragma once
#include <SFML/System/Vector2.hpp>


namespace th {


    class Transform {

        public:
            sf::Vector2f pos;
            sf::Vector2f size;
            sf::Vector2f boxCollideScale = {1.f, 1.f};
            sf::Vector2f direction;
            sf::Vector2f scale = {1.f, 1.f};
            float rotation = 0.f;
            float speed = 0.f;
        
        public:
            Transform() = default;
            Transform(
                sf::Vector2f pos,
                sf::Vector2f size,
                sf::Vector2f boxCollideScale,
                sf::Vector2f direction,
                sf::Vector2f scale,
                float rotation,
                float speed
            );
            
            float left() const;
            float top() const;
            float right() const;
            float bottom() const;

            void setLeft(float left);
            void setTop(float top);
            void setRight(float right);
            void setBottom(float bottom);

            float width() const;
            float height() const;
            void setWidth(float width);
            void setHeight(float width);

            float centerX() const;
            float centerY() const;
            void setCenterX(float centerX);
            void setCenterY(float centerY);

            sf::Vector2f center() const;
            void setCenter(sf::Vector2f center);

            void move(float dt);
            void move(sf::Vector2f distance);
            
            bool collide(const th::Transform& t) const;
            bool collideWithShrink(th::Transform& t);

    };
    
} // namespace th
