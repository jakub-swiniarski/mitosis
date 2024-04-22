#ifndef DISK_HPP
#define DISK_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Disk : public sf::CircleShape {
public:
    float get_distance(float x, float y) const;
    sf::Vector2f get_middle(void) const;
};

#endif
