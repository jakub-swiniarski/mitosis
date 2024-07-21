#ifndef FOOD_HPP
#define FOOD_HPP

#include "Disk.hpp"

class Food : public Disk {
public:
    Food(sf::Vector2f player_position);
};

#endif // FOOD_HPP
