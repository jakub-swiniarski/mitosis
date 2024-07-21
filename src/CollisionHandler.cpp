#include "CollisionHandler.hpp"
#include "Counter.hpp"
#include "Food.hpp"
#include "Cell.hpp"

CollisionHandler::CollisionHandler(DrawableContainer& drawables)
    : cells(drawables.cells),
      food(drawables.food),
      counter(drawables.counter) {}

void CollisionHandler::update(void) {
    for (auto c = cells.begin(); c != cells.end(); c++) {
        for (auto c1 = cells.begin(); c1 != cells.end(); c1++) {
            if (c != c1 &&
                c->collision(*c1) &&
                c->getRadius() > c1->getRadius()) {
                if (c1 == cells.begin())
                    exit(0); // TODO: game over screen, display final radius of your cell
                c->grow(c1->getRadius() / 10.0f);
                c1 = cells.erase(c1); // erase() returns the next valid iterator. When the loop ends, c1 gets incremented. To avoid skipping an element, we need to go back.
                c1--;
                counter.update(-1);
            }
        }

        for (auto f = food.begin(); f != food.end(); f++) {
            if (f->collision(*c)) {
                c->grow(f->getRadius());
                f = food.erase(f);
                f--;
            }
        }
    }
}
