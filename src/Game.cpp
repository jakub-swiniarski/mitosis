#include <SFML/Graphics/RenderWindow.hpp>

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
    if (camera_rect.intersects(enemy.getGlobalBounds()))
        window->draw(enemy);
    window->draw(player);
    
    window->display();
}

Game::Game(sf::RenderWindow *w) : enemy(sf::Vector2f(50.f, 50.f)), player(sf::Vector2f(0.f, 0.f)){
    window = w;
    w->setFramerateLimit(cfg::window::fps);
}

void Game::run(void) {
    CollisionHandler collision_handler(&enemy, &player, &food);
    sf::Clock dt_clock;
    EventHandler event_handler(window);
    InputProcessor input_processor(&player, window);
    Timer spawn_timer(cfg::food::spawn_cooldown);

    while (window->isOpen()) {
        const float dt = dt_clock.restart().asSeconds();

        collision_handler.update();
        event_handler.update();
        input_processor.update();

        enemy.update(dt);
        player.update(dt);

        /* TODO: spawner class and simplify spawning algorithm */
        if (spawn_timer.elapsed())
            food.push_front(Food(player.getPosition()));

        camera = window->getView();
        camera.setCenter(player.get_middle());
        window->setView(camera);

        draw();
    }
}
