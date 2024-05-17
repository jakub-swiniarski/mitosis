#include "Counter.hpp"

#include "config.hpp"
#include <string>

Counter::Counter(int v, sf::Vector2f pos, sf::Font *f) : value(v) {
    text.setPosition(pos);
    text.setFont(*f);
    text.setCharacterSize(cfg::text::size);
}

sf::Text &Counter::get_text(void) {
    return text;
}

void Counter::update(int diff) {
    value += diff;
    text.setString(std::to_string(value));
}
