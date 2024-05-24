#ifndef COLLISIONHANDLER_HPP
#define COLLISIONHANDLER_HPP

#include "DrawableContainer.hpp"

class Cell;
class Counter;
class Food;

class CollisionHandler {
    std::list<Cell> *cells;
    std::list<Food> *food;
    Counter *counter;

public:
    CollisionHandler(DrawableContainer *dc);
    void update(void);
};

#endif /* COLLISIONHANDLER_HPP */
