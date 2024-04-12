#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics/CircleShape.hpp>

class Ball: public sf::CircleShape {
    float speed_x, speed_y;

public:
    Ball(float x, float y);
    void set_speed(float x, float y);
    void update(float mod);
};

#endif /* BALL_HPP */
