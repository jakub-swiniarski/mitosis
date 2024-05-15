#include "CollisionHandler.hpp"
#include "Food.hpp"
#include "Cell.hpp"

CollisionHandler::CollisionHandler(std::list<Cell> *c, std::list<Food> *f) : cells(c), food(f) {}

void CollisionHandler::update(void) {
    for (auto f = food->begin(); f != food->end(); f++) {
        for (auto c = cells->begin(); c != cells->end(); c++) {
            if (f->collision(&(*c))) {
                c->grow(f->getRadius());
                food->erase(f);
                //break; /* TODO: avoid break and others */
                return;
            }
        }
    }
}
