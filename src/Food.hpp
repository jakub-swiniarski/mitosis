#ifndef FOOD_HPP
#define FOOD_HPP

#include <SFML/Graphics/CircleShape.hpp>

class Food : public sf::CircleShape {
public:
    Food(float player_x, float player_y);
    float get_distance(float x, float y) const;
};

#endif /* FOOD_HPP */
