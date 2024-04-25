#include <forward_list>

#include "CollisionHandler.hpp"
#include "Food.hpp"
#include "Cell.hpp"

CollisionHandler::CollisionHandler(Cell *e, Cell *p, std::forward_list<Food> *f) {
    enemy = e;
    player = p;
    food = f;
}

void CollisionHandler::update(void) {
    auto prev = food->before_begin();
    for (auto i = food->before_begin(); i != food->end(); i++) {
        if (i->collision(player)) { /* TODO: don't repeat the same code, enemy and player are both disks */
            player->grow(i->getRadius());
            food->erase_after(prev);
            break;
        } else if (i->collision(enemy)) {
            enemy->grow(i->getRadius());
            food->erase_after(prev);
            break;
        }
        prev = i;
    }
}
