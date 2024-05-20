#include "Counter.hpp"

#include "config.hpp"

Counter::Counter(int v, std::string l, sf::Vector2f pos, sf::Font &f) : value(v), label(l) {
    text.setPosition(pos);
    text.setFont(f);
    text.setCharacterSize(cfg::text::size);
    text.setString(label + std::to_string(value));
}

sf::Text &Counter::get_text(void) {
    return text;
}

void Counter::update(int diff) {
    value += diff;
    text.setString(label + std::to_string(value));
}
