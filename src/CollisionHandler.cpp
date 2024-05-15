#include "CollisionHandler.hpp"
#include "Food.hpp"
#include "Cell.hpp"

CollisionHandler::CollisionHandler(std::list<Cell> *c, std::list<Food> *f) : cells(c), food(f) {}

void CollisionHandler::update(void) {
    for (auto c = cells->begin(); c != cells->end(); c++) {
        for (auto c1 = cells->begin(); c1 != cells->end(); c1++) {
            if (c != c1 && c->collision(&(*c1))) {
                if (c->getRadius() > c1->getRadius()) {
                    c->grow(c1->getRadius());
                    cells->erase(c1);
                } else {
                    c1->grow(c->getRadius());
                    cells->erase(c);
                }
                return;
            }
        }

        for (auto f = food->begin(); f != food->end(); f++) {
            if (f->collision(&(*c))) {
                c->grow(f->getRadius());
                food->erase(f);
                //break; /* TODO: avoid break and others */
                return;
            }
        }
    }
}
