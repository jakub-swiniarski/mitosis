#ifndef COLLISIONHANDLER_HPP
#define COLLISIONHANDLER_HPP

#include <list>

class Cell;
class Counter;
class Food;

class CollisionHandler {
    std::list<Cell> *cells;
    std::list<Food> *food;
    Counter *counter;

public:
    CollisionHandler(std::list<Cell> *c, std::list<Food> *f, Counter *ctr);
    void update(void);
};

#endif /* COLLISIONHANDLER_HPP */
