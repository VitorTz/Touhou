#pragma once
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>


namespace th {


    template<typename T>
    void printVector(const sf::Vector2<T>&v ) {
        std::cout << "Vector(" << v.x << ", " << v.y << ")\n";
    }

    void normalizeVector(sf::Vector2f& v);

    
} // namespace th
