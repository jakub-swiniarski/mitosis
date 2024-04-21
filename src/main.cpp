#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <forward_list>

#include "AIBall.hpp"
#include "EventHandler.hpp"
#include "Food.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

/* function declarations */
static void draw(void);
static void run(void);
static void setup(void);

/* variables */
static sf::View camera;
static AIBall enemy(50.f, 50.f);
static std::forward_list<Food> food;
static Ball player(0.f, 0.f);
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
    sf::Clock dt_clock;
    EventHandler event_handler(&window);
    InputProcessor input_processor(&player, &window);
    sf::Clock spawn_clock;

    while (window.isOpen()) {
        float dt = dt_clock.restart().asSeconds();

        event_handler.update();
        input_processor.update();

        enemy.update(dt);
        player.update(dt);

        /* TODO: spawner class and simplify spawning algorithm */
        if (spawn_clock.getElapsedTime().asSeconds() >= cfg::food::spawn_cooldown) {
            spawn_clock.restart();
            food.push_front(Food(player.getPosition().x, player.getPosition().y));
        }

        auto prev = food.before_begin();
        for (auto i = food.before_begin(); i != food.end(); i++) {
            if (i->get_distance(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius()) <= i->getRadius() + player.getRadius()) { /* TODO use get_middle method */
                player.grow(i->getRadius());
                food.erase_after(prev);
                break;
            } else if (i->get_distance(enemy.getPosition().x + enemy.getRadius(), enemy.getPosition().y + enemy.getRadius()) <= i->getRadius() + enemy.getRadius()) {
                enemy.grow(i->getRadius());
                food.erase_after(prev);
                break;
            }
            prev = i;
        }

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
