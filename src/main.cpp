#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <forward_list>

#include "AICell.hpp"
#include "CollisionHandler.hpp"
#include "EventHandler.hpp"
#include "Food.hpp"
#include "InputProcessor.hpp"
#include "Timer.hpp"

#include "config.hpp"

/* function declarations */
static void draw(void);
static void run(void);
static void setup(void);

/* variables */
static sf::View camera;
static AICell enemy(sf::Vector2f(50.f, 50.f));
static std::forward_list<Food> food;
static Cell player(sf::Vector2f(0.f, 0.f));
static sf::RenderWindow window(sf::VideoMode(cfg::window::width, cfg::window::height), "Mitosis", sf::Style::None);

/* constants */
static const std::string filepath = "res/";

/* function implementations */
void draw(void) {
    sf::FloatRect camera_rect(
        camera.getCenter().x - camera.getSize().x / 2.f,
        camera.getCenter().y - camera.getSize().y / 2.f,
        camera.getSize().x,
        camera.getSize().y
    );
    
    window.clear();
    
    for (const auto &i : food)
        if (camera_rect.intersects(i.getGlobalBounds()))
            window.draw(i);
    if (camera_rect.intersects(enemy.getGlobalBounds()))
        window.draw(enemy);
    window.draw(player);
    
    window.display();
}

void run(void) {
    CollisionHandler collision_handler(&enemy, &player, &food);
    sf::Clock dt_clock;
    EventHandler event_handler(&window);
    InputProcessor input_processor(&player, &window);
    Timer spawn_timer(cfg::food::spawn_cooldown);

    while (window.isOpen()) {
        float dt = dt_clock.restart().asSeconds();

        collision_handler.update();
        event_handler.update();
        input_processor.update();

        enemy.update(dt);
        player.update(dt);

        /* TODO: spawner class and simplify spawning algorithm */
        if (spawn_timer.elapsed())
            food.push_front(Food(player.getPosition()));

        camera = window.getView();
        camera.setCenter(player.get_middle());
        window.setView(camera);

        draw();
    }
}

void setup(void) {
    window.setFramerateLimit(cfg::window::fps);
}

int main(void) {
    setup();    
    run();

    return 0;
}
