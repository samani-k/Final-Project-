#include <iostream>
#include <string> 
#include "Character.h"
#ifndef RIVAL_H
#define RIVAL_H

class Rival : public Character {
    private:
    // Extra Credit Variables
    int skillLevel;
    bool banned;
    bool defeated;

    public: 
    
    // Default
    Rival ();

    // Parameterized
    Rival (string n, string l, string r, string d, int s);

    // Getters

    int getskillLevel(); 
    bool getBanned();
    bool getDefeated();

    // Setters
   void setBanned (bool status);
   void setDefeated (bool status);

    // Display Function

    void displayRival();
};

#endif