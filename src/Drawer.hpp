#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <list>
#include <SFML/Graphics/Rect.hpp>

class Cell;
class Food;
class Counter;
struct DrawableContainer;
namespace sf {
    class RenderWindow;
    class View;
}

class Drawer {
    // ----- CORE ----- //
    sf::RenderWindow& window;
    sf::View&         camera;
    sf::FloatRect     camera_rect;

    // ----- DRAWABLES ----- //
    std::list<Cell>& cells;
    std::list<Food>& food;
    Counter&         counter;

    template<class T>
    void draw_container(T& c);

public:
    Drawer(sf::RenderWindow& window, sf::View& camera, DrawableContainer& drawables);

    void update(void);
};

#endif // DRAWER_HPP
