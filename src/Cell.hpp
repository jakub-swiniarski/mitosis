#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics/CircleShape.hpp>

class Cell : public sf::CircleShape {
protected:
    float speed_x, speed_y;

public:
    Cell(float x, float y);
    sf::Vector2f get_middle(void) const;
    void grow(float radius);
    void set_speed(float x, float y);
    void update(float mod);
};

#endif /* BALL_HPP */
