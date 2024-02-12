#include "../../include/util/util.hpp"


void th::normalizeVector(sf::Vector2f& v) {
    const float m = std::sqrt(v.x * v.x + v.y * v.y);    
    if (m > 1) {
        v.x /= m;
        v.y /= m;
    }
}