#include <SFML/Graphics/RenderWindow.hpp>
#include <stdexcept>

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
#endif // DEBUG

Game::Game(sf::RenderWindow& window)
    : window(window),
      counter(cfg::ai::num, "ENEMIES: ", sf::Vector2f(20.0f, 2.0f), font) {
#ifdef DEBUG
    res_path = "res/";
#else
    window.setFramerateLimit(cfg::window::fps);
    res_path = "/usr/local/share/mitosis/";
#endif // DEBUG

    if (!font.loadFromFile(res_path + "font.ttf"))
        throw std::runtime_error("Failed to load font.");

    cells.push_back(Cell(sf::Vector2f(0.0f, 0.0f), 0));
    for (int i = 0; i < cfg::ai::num; i++)
        cells.push_back(Cell(sf::Vector2f(50.f, 50.f), 1));

    player = &cells.front();
}

void Game::run(void) {
    // TODO: vector or list of ui elements
    DrawableContainer drawables = {
        .cells   = cells,
        .food    = food,
        .counter = counter
    };

    sf::Clock        dt_clock;
    CollisionHandler collision_handler(drawables);
    Drawer           drawer(window, camera, drawables);
    EventHandler     event_handler(window);
    InputProcessor   input_processor(player, window);
    Timer            spawn_timer(cfg::food::spawn_cooldown);

#ifdef DEBUG
    float fps_avg = 1.0f;
    Timer fps_timer(0.5f);
#endif // DEBUG

    while (window.isOpen()) {
        const float dt = dt_clock.restart().asSeconds();

        collision_handler.update();
        event_handler.update();
        input_processor.update();

        for (auto& i : cells)
            i.update(dt);

        if (spawn_timer.elapsed())
            food.push_front(Food(player->getPosition()));

        camera = window.getView();
        camera.setCenter(player->get_middle());
        window.setView(camera);

        drawer.update();

#ifdef DEBUG
        fps_avg = 0.9f * fps_avg + 0.1f * (1.0f / dt);
        if (fps_timer.elapsed()) 
            std::cout << fps_avg << '\n';
#endif // DEBUG
    }
}
