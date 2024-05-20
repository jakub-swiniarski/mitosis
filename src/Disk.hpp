#ifndef DISK_HPP
#define DISK_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Disk : public sf::CircleShape {
public:
    bool collision(const Disk &d) const;
    float get_distance(sf::Vector2f v) const;
    sf::Vector2f get_middle(void) const;
};

#endif /* DISK_HPP */
