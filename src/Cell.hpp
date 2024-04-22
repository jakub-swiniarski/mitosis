#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/System/Vector2.hpp>

#include "Disk.hpp"

class Cell : public Disk {
protected:
    sf::Vector2f speed;

public:
    Cell(sf::Vector2f v);
    void grow(float radius);
    void set_speed(sf::Vector2f v);
    void update(float mod);
};

#endif /* BALL_HPP */
