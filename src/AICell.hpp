#ifndef AICELL_HPP
#define AICELL_HPP

#include <SFML/System/Clock.hpp>

#include "Cell.hpp"

class AICell : public Cell {
    sf::Clock clock;

public:
    using Cell::Cell;
    void update(float mod);
};

#endif /* AICELL_HPP */
