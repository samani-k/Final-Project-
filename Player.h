#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>
using namespace std;

class Player : public Character {
private:
    int followers;
    int money;
    string location;

public:
    Player();

    int getFollowers();
    int getMoney();
    string getLocation();

    void addFollowers(int amount);
    void addMoney(int amount);
    void moveTo(string newLocation);
    void displayStats();
};

#endif
