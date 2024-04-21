#include "Ball.hpp"

class AIBall : public Ball {
public:
    using Ball::Ball;
    void update(float mod);
};
