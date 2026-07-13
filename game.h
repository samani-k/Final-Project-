#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Restaurant.h"
#include <string> 

class Game {
private:
    Player player;
    Restaurant restaurant;
    bool running;

public:
    Game();

    void start();
    void showMenu();
    void showStats();
    void travel();
    void film();
    
    bool loadRestaurant(string filename);
};

#endif
