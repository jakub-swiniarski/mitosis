#include <SFML/Graphics/RenderWindow.hpp>

#include "Cell.hpp"
#include "CollisionHandler.hpp"
#include "EventHandler.hpp"
#include "Game.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

void Game::draw(void) { /* TODO: drawer class? */
    sf::FloatRect camera_rect(
        camera.getCenter().x - camera.getSize().x / 2.f,
        camera.getCenter().y - camera.getSize().y / 2.f,
        camera.getSize().x,
        camera.getSize().y
    );
    
    window->clear();
    
    for (const auto &i : food)
        if (camera_rect.intersects(i.getGlobalBounds()))
            window->draw(i);
    for (const auto &i : cells)
        if (camera_rect.intersects(i.getGlobalBounds()))
            window->draw(i);
    
    window->display();
}

Game::Game(sf::RenderWindow *w) : window(w) {
    w->setFramerateLimit(cfg::window::fps);

    cells.push_back(Cell(sf::Vector2f(0.f, 0.f), 0));
    for (int i = 0; i < cfg::ai::num; i++)
        cells.push_back(Cell(sf::Vector2f(50.f, 50.f), 1));
}

void Game::run(void) {
    CollisionHandler collision_handler(&cells, &food);
    sf::Clock dt_clock;
    EventHandler event_handler(window);
    InputProcessor input_processor(&cells.front(), window);
    Timer spawn_timer(cfg::food::spawn_cooldown);

    while (window->isOpen()) {
        const float dt = dt_clock.restart().asSeconds();

        collision_handler.update();
        event_handler.update();
        input_processor.update();

        for (auto &i : cells)
            i.update(dt);

        /* TODO: spawner class and simplify spawning algorithm */
        if (spawn_timer.elapsed())
            food.push_front(Food(cells.front().getPosition()));

        camera = window->getView();
        camera.setCenter(cells.front().get_middle()); /* TODO: player = cells front, do the same in other files */
        window->setView(camera);

        draw();
    }
}
