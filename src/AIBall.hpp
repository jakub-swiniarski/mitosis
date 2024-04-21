#include <SFML/System/Clock.hpp>

#include "Ball.hpp"

class AIBall : public Ball {
    sf::Clock clock;

public:
    using Ball::Ball;
    void update(float mod);
};
