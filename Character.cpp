#include "Character.h"
#include <iostream>

using namespace std;

// Default constructor
Character::Character() {
    name = "";
    role = "";
}

// Parameterized constructor
Character::Character(string n, string r) {
    name = n;
    role = r;
}


// Getters
string Character::getName() {
    return name;
}

string Character::getRole() {
    return role;
}

//Setters
void Character::setName(string n) { 
    name = n; 
}
void Character::setRole(string r) { 
    role = r; 
}
// Prints dialogue
void Character::talk() {
     cout << name << " has nothing to say." << endl; 
    }
