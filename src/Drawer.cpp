#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Cell.hpp"
#include "Counter.hpp"
#include "DrawableContainer.hpp"
#include "Drawer.hpp"
#include "Food.hpp"
    
Drawer::Drawer(sf::RenderWindow *w, sf::View *c, DrawableContainer *dc) : window(w), camera(c), cells(dc->cells), food(dc->food), counter(dc->counter) {}

void Drawer::update(void) {
    sf::FloatRect camera_rect(
        camera->getCenter().x - camera->getSize().x / 2.f,
        camera->getCenter().y - camera->getSize().y / 2.f,
        camera->getSize().x,
        camera->getSize().y
    );
    
    window->clear();
    
    for (const auto &i : *cells)
        if (camera_rect.intersects(i.getGlobalBounds()))
            window->draw(i);
    for (const auto &i : *food)
        if (camera_rect.intersects(i.getGlobalBounds()))
            window->draw(i);

    window->setView(window->getDefaultView());
    window->draw(counter->get_text());
    
    window->display();
}
