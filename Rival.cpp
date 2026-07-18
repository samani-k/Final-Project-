#include "Rival.h"
#include <iostream>
using namespace std;

//Inheritance 

//Getters
Rival::Rival() : Character() {
    location = "";
    dialogue = "";
    skillLevel = 0;
    banned = false;
}

//Parameterized 
Rival::Rival(string n, string loc, string role, string d, int skill)
    : Character(n, role) {
    location = loc;
    dialogue = d;
    skillLevel = skill;
    banned = false;
}

// Getters
string Rival::getLocation() {
    return location;
}

string Rival::getDialogue() {
    return dialogue;
}

int Rival::getSkillLevel() {
    return skillLevel;
}
// Getter to see if rival is banned
bool Rival::getBanned() {
    return banned;
}

//Setter for banned condition 
void Rival::setBanned(bool value) {
    banned = value;
}

// Talk function 
void Rival::talk() {
    cout << getName() << ": \"" << dialogue << "\"" << endl;
}