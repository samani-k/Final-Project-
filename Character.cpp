#include "Character.h"
#include <iostream>
using namespace std;

Character::Character() {
    name = "";
}

Character::Character(string n) {
    name = n;
}

string Character::getName() {
    return name;
}

void Character::setName(string n) {
    name = n;
}

void Character::display() {
    cout << "Name: " << name << endl;
}

// hi 