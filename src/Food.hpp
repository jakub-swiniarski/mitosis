#ifndef FOOD_HPP
#define FOOD_HPP

#include "Disk.hpp"

class Food : public Disk {
public:
    Food(sf::Vector2f player_pos);
};

#endif /* FOOD_HPP */
