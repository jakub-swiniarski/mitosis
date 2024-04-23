#include <cmath>

#include "Disk.hpp"

sf::Vector2f Disk::get_middle(void) const {
    return sf::Vector2f(
        getPosition().x + getRadius(),
        getPosition().y + getRadius()
    );
}

float Disk::get_distance(sf::Vector2f v) const {
    return sqrt(
        pow(get_middle().x - v.x, 2)
        + pow(get_middle().y - v.y, 2)
    );
}
