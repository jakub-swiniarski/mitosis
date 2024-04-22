#include <SFML/System/Clock.hpp>

#include "Cell.hpp"

class AICell : public Cell {
    sf::Clock clock;

public:
    using Cell::Cell;
    void update(float mod);
};
