#include <string>
#include "Rival.h"
#include "Food.h"
#ifndef RESTAURANT_H
#define RESTAURANT_H

using namespace std;

class Restaurant {
    private:
    string name;
    Food foods [4]; // Each restaurant only has 4 foods, set size
    Rival rival; // Each restaurant has its own featured creator/rival
    bool unlocked; // Restaurant open or closed
    bool playerFeatured; 
    bool competitionCompleted;
    int competitionDay; //Competiton linked to a certain day

    public: 
//Default Constructor 
   Restaurant ();
//Parameterized Constructor 
   Restaurant (string n, bool u, int cd);
// Getters
    string getName();
    bool getUnlocked();
    bool getplayerFeatured();
    bool getcompetitionCompleted();
    int getcompetitionDay();
    Rival getRival ();
    Food getFood(int ind);
// Setters
    void setUnlocked(bool status);
    void setplayerFeatured(bool status);
    void setcompetitionCompleted(bool status);
    void setRival(Rival r);
    void setFood(int ind, Food newFood); 

//Methods
int countUnlockedFoods (int playerFollowers);
void displayFoods (int playerFollowers);
void displayRestaurant(); 

};

#endif