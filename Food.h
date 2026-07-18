#include <string>
#ifndef FOOD_H
#define FOOD_H

using namespace std;  

class Food {
private:
    string name;
    int price;
    int followerRequirement; //Requirement for Food unlocks, Restaurant unlocks
    int contentBonus; //Bonus for content

public:
// Default and Parameterized
    Food();
    Food(string n, int p, int req, int bonus);

//Methods 
    string getName();
    int getPrice();
    int getFollowerRequirement();
    int getContentBonus();
    
//Locked/Unlocked Food based on followers
    bool isUnlocked(int followers);
};

#endif
