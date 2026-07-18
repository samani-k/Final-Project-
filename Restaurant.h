#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Food.h"
#include "Rival.h"
#include <string>
using namespace std;

class Restaurant {
private:
    string name;
    bool unlocked;
    int competitionDay;
    Food foods[4];
    Rival rival;

public:

//Constructors 
    Restaurant();
    Restaurant(string n, bool u, int day);

//Getters
    string getName();
    bool getUnlocked();
    int getCompetitionDay();
    Food getFood(int index);
    Rival getRival();

//Setters
    void setUnlocked(bool value);
    void setFood(int index, Food food);
    void setRival(Rival r);
    void displayFoods(int followers);
};

#endif
