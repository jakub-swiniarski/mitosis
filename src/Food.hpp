#ifndef FOOD_HPP
#define FOOD_HPP

#include "Disk.hpp"

class Food : public Disk {
public:
    Food(float player_x, float player_y);
};

#endif /* FOOD_HPP */
