#include <string>
#ifndef FOOD_H
#define FOOD_H

using namespace std;  

class Food {
private:
    string name;
    int price;
    int followerRequirement;
    int contentBonus;

public:
    Food();
    Food(string n, int p, int req, int bonus);

    string getName();
    int getPrice();
    int getFollowerRequirement();
    int getContentBonus();
    bool isUnlocked(int followers);
};

#endif
