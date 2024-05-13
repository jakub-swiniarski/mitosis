#ifndef COLLISIONHANDLER_HPP
#define COLLISIONHANDLER_HPP

#include <forward_list>

class Cell;
class Food;

class CollisionHandler {
    Cell *enemy;
    Cell *player;
    std::forward_list<Food> *food;

public:
    CollisionHandler(Cell *e, Cell *p, std::forward_list<Food> *f);
    void update(void);
};

#endif /* COLLISIONHANDLER_HPP */
