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
        pow(getPosition().x + getRadius() - v.x, 2)
        + pow(getPosition().y + getRadius() - v.y, 2)
    );
}
