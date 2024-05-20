#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Cell.hpp"
#include "Counter.hpp"
#include "DrawableContainer.hpp"
#include "Drawer.hpp"
#include "Food.hpp"

template<class T>
void Drawer::draw_container(T *c) {
    for (const auto &i : *c)
        if (camera_rect.intersects(i.getGlobalBounds()))
            window->draw(i);
}
    
Drawer::Drawer(sf::RenderWindow *w, sf::View *c, DrawableContainer *dc) : window(w), camera(c), cells(dc->cells), food(dc->food), counter(dc->counter) {}

void Drawer::update(void) {
    camera_rect = sf::FloatRect(
        camera->getCenter().x - camera->getSize().x / 2.f,
        camera->getCenter().y - camera->getSize().y / 2.f,
        camera->getSize().x,
        camera->getSize().y
    );
    
    window->clear();
    
    draw_container(cells);
    draw_container(food);

    window->setView(window->getDefaultView());
    window->draw(counter->get_text());
    
    window->display();
}
