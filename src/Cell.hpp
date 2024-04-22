#ifndef BALL_HPP
#define BALL_HPP

#include "Disk.hpp"

class Cell : public Disk {
protected:
    float speed_x, speed_y;

public:
    Cell(float x, float y);
    void grow(float radius);
    void set_speed(float x, float y);
    void update(float mod);
};

#endif /* BALL_HPP */
