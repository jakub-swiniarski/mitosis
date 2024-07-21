#include <cmath>

#include "Disk.hpp"

bool Disk::collision(const Disk& disk) const {
    if (get_distance(disk.get_middle()) <= getRadius() + disk.getRadius()) 
        return 1;
    return 0;
}

float Disk::get_distance(sf::Vector2f point) const {
    return sqrt(
        pow(get_middle().x - point.x, 2) +
        pow(get_middle().y - point.y, 2)
    );
}

sf::Vector2f Disk::get_middle(void) const {
    return sf::Vector2f(
        getPosition().x + getRadius(),
        getPosition().y + getRadius()
    );
}
