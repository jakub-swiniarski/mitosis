#include <cmath>

#include "Disk.hpp"

sf::Vector2f Disk::get_middle(void) const {
    sf::Vector2f middle(getPosition().x + getRadius(), getPosition().y + getRadius());
    return middle;
}

float Disk::get_distance(float x, float y) const {
    return sqrt(
        pow(getPosition().x + getRadius() - x, 2)
        + pow(getPosition().y + getRadius() - y, 2)
    );
}
