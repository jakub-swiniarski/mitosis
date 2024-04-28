#ifndef AICELL_HPP
#define AICELL_HPP

#include "Cell.hpp"
#include "Timer.hpp"

class AICell : public Cell {
    Timer timer;

public:
    AICell(sf::Vector2f v);
    void update(float mod);
};

#endif /* AICELL_HPP */
