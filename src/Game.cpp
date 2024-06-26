#include <SFML/Graphics/RenderWindow.hpp>

#include "Cell.hpp"
#include "CollisionHandler.hpp"
#include "DrawableContainer.hpp"
#include "Drawer.hpp"
#include "EventHandler.hpp"
#include "Game.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

#ifdef DEBUG
#include <iostream>
#endif /* DEBUG */

Game::Game(sf::RenderWindow *w) : window(w), counter(cfg::ai::num, "ENEMIES: ", sf::Vector2f(20.f, 2.f), font) {
#ifdef DEBUG
    filepath = "res/";
#else
    w->setFramerateLimit(cfg::window::fps);
    filepath = "/usr/local/share/mitosis/";
#endif /* DEBUG */

    font.loadFromFile(filepath + "font.ttf");

    cells.push_back(Cell(sf::Vector2f(0.f, 0.f), 0));
    for (int i = 0; i < cfg::ai::num; i++)
        cells.push_back(Cell(sf::Vector2f(50.f, 50.f), 1));

    player = &cells.front();
}

void Game::run(void) {
    /* TODO: vector or list of ui elements */
    DrawableContainer drawables = {
        .cells = &cells,
        .food = &food,
        .counter = &counter
    };

    CollisionHandler collision_handler(&drawables);
    Drawer drawer(window, &camera, &drawables);
    sf::Clock dt_clock;
    EventHandler event_handler(window);
    InputProcessor input_processor(player, window);
    Timer spawn_timer(cfg::food::spawn_cooldown);

#ifdef DEBUG
    float fps_avg = 1.f;
    Timer fps_timer(0.5);
#endif /* DEBUG */

    while (window->isOpen()) {
        const float dt = dt_clock.restart().asSeconds();

        collision_handler.update();
        event_handler.update();
        input_processor.update();

        for (auto &i : cells)
            i.update(dt);

        if (spawn_timer.elapsed())
            food.push_front(Food(player->getPosition()));

        camera = window->getView();
        camera.setCenter(player->get_middle());
        window->setView(camera);

        drawer.update();

#ifdef DEBUG
        fps_avg = 0.9 * fps_avg + 0.1 * (1 / dt);
        if (fps_timer.elapsed()) 
            std::cout << fps_avg << '\n';
#endif /* DEBUG */
    }
}
