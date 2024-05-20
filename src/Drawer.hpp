#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <SFML/Graphics/Rect.hpp>

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
    sf::FloatRect camera_rect;
    std::list<Cell> *cells;
    std::list<Food> *food;
    Counter *counter;

    template<class T>
    void draw_container(T *c);

public:
    Drawer(sf::RenderWindow *w, sf::View *c, DrawableContainer *dc);
    void update(void);
};

#endif /* DRAWER_HPP */
