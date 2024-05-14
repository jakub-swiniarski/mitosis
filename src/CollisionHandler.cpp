#include "CollisionHandler.hpp"
#include "Food.hpp"
#include "Cell.hpp"

CollisionHandler::CollisionHandler(std::forward_list<Cell> *c, std::forward_list<Food> *f) : cells(c), food(f) {}

void CollisionHandler::update(void) {
    auto prev = food->before_begin();
    for (auto f = food->begin(); f != food->end(); f++) {
        for (auto c = cells->begin(); c != cells->end(); c++) {
            if (f->collision(&(*c))) {
                c->grow(f->getRadius());
                food->erase_after(prev);
                //break; /* TODO: avoid break and others */
                return;
            }
        }
        prev = f;
    }
}
