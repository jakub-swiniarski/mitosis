#ifndef DRAWABLECONTAINER_HPP
#define DRAWABLECONTAINER_HPP

#include <list>

class Cell;
class Food;
class Counter;

struct DrawableContainer {
    std::list<Cell>& cells;
    std::list<Food>& food;
    Counter&         counter;
};

#endif // DRAWABLECONTAINER_HPP
