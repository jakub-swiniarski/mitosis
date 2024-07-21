#ifndef CELL_HPP
#define CELL_HPP

#include "Disk.hpp"
#include "Timer.hpp"
#include <random>

class Cell : public Disk {
    // ----- CORE ----- //
    sf::Vector2f speed;

    // ----- AI ----- //
    Timer                                                    timer;
    bool                                                     is_ai;
    std::mt19937                                             rng;
    std::uniform_int_distribution<std::mt19937::result_type> rand_rotation;

    void update_ai(void);

public:
    Cell(sf::Vector2f position, bool is_ai);

    void grow(float radius);
    void set_speed(sf::Vector2f speed);
    void update(float mod);
};

#endif // CELL_HPP
