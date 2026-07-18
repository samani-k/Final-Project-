#ifndef RIVAL_H
#define RIVAL_H

#include "Character.h"
#include <string>
using namespace std;

//Inheritance 
class Rival : public Character {
private:
    string location;
    string dialogue;
    int skillLevel;
    bool banned;

public:
//Constructors
    Rival();
    Rival(string n, string loc, string role, string d, int skill);

    //Getters
    string getLocation();
    string getDialogue();
    int getSkillLevel();
    bool getBanned();
    
    //Setters
    void setBanned(bool value);
    //Talk Function
    void talk();
};

#endif
