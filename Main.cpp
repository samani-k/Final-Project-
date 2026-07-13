#include "Game.h"

int main() {
    Game game;
 if (!game.loadRestaurant("restaurant.txt")) {
        return 1;
 }

    game.start();

    return 0;
}
