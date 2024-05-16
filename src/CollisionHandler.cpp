#include "CollisionHandler.hpp"
#include "Food.hpp"
#include "Cell.hpp"

CollisionHandler::CollisionHandler(std::list<Cell> *c, std::list<Food> *f) : cells(c), food(f) {}

void CollisionHandler::update(void) {
    for (auto c = cells->begin(); c != cells->end(); c++) {
        for (auto c1 = cells->begin(); c1 != cells->end(); c1++) {
            if (c != c1 && c->collision(&(*c1))) {
                if (c->getRadius() > c1->getRadius()) {
                    if (c1 == cells->begin())
                        exit(0); /* TODO: game over screen */
                    c->grow(c1->getRadius());
                    c1 = cells->erase(c1); /* erase() returns the next valid iterator. When the loop ends, c1 gets incremented. To avoid skipping an element, we need to go back. */
                    c1--;
                }
            }
        }

        for (auto f = food->begin(); f != food->end(); f++) {
            if (f->collision(&(*c))) {
                c->grow(f->getRadius());
                f = food->erase(f);
                f--;
            }
        }
    }
}
