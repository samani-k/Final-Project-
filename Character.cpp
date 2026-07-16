#include "Character.h"
#include <iostream>

using namespace std;

// Default constructor
Character::Character() {
    name = "";
    location = "";
    role = "";
    dialogue = "";
}

// Parameterized constructor
Character::Character(string n, string l, string r, string d) {
    name = n;
    location = l;
    role = r;
    dialogue = d;
}

// Getters
string Character::getName() {
    return name;
}

string Character::getLocation() {
    return location;
}

string Character::getRole() {
    return role;
}

string Character::getDialogue() {
    return dialogue;
}

// Prints the dialogue
void Character::talk() {
    cout << name << " says:" << endl;
    cout << "\"" << dialogue << "\"" << endl;
}

// Displays character information
void Character::displayCharacter() {
    cout << name << " - " << role << endl;
    cout << "Location: " << location << endl;
}