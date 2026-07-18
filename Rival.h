#ifndef RIVAL_H
#define RIVAL_H

#include "Character.h"
#include <string>
using namespace std;

class Rival : public Character {
private:
    string location;
    string dialogue;
    int skillLevel;
    bool banned;

public:
    Rival();
    Rival(string n, string loc, string role, string d, int skill);

    string getLocation();
    string getDialogue();
    int getSkillLevel();
    bool getBanned();
    void setBanned(bool value);
    void talk();
};

#endif
