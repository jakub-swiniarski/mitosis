#ifndef COLLISIONHANDLER_HPP
#define COLLISIONHANDLER_HPP

#include <list>

class Cell;
class Food;

class CollisionHandler {
    std::list<Cell> *cells;
    std::list<Food> *food;

public:
    CollisionHandler(std::list<Cell> *c, std::list<Food> *f);
    void update(void);
};

#endif /* COLLISIONHANDLER_HPP */
