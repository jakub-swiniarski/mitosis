#ifndef FOOD_HPP
#define FOOD_HPP

#include <SFML/Graphics/CircleShape.hpp>

class Food : public sf::CircleShape {
public:
    Food(float player_x, float player_y);
};

#endif /* FOOD_HPP */
