#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <list>

class Cell;
class Food;
class Counter;
struct DrawableContainer;
namespace sf {
    class RenderWindow;
    class View;
}

class Drawer {
    sf::RenderWindow *window;
    sf::View *camera;
    std::list<Cell> *cells;
    std::list<Food> *food;
    Counter *counter;

public:
    Drawer(sf::RenderWindow *w, sf::View *c, DrawableContainer *dc);
    void update(void);
};

#endif /* DRAWER_HPP */
