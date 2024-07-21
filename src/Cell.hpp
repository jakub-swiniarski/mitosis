#ifndef CELL_HPP
#define CELL_HPP

#include "Disk.hpp"
#include "Timer.hpp"

class Cell : public Disk {
    sf::Vector2f speed;
    Timer        timer;
    bool         is_ai;

    void update_ai(void);

public:
    Cell(sf::Vector2f position, bool is_ai);

    void grow(float radius);
    void set_speed(sf::Vector2f speed);
    void update(float mod);
};

#endif // CELL_HPP
