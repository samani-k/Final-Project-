#include <string>
#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;


class Character {
private:
    string name;
    string location;
    string role;
    string dialogue;

public:
    // Constructors
    Character();
    Character(string n, string l, string r, string d);

    // Getters
    string getName();
    string getLocation();
    string getRole();
    string getDialogue();

    // Display functions
    void talk();
    void displayCharacter();
};



#endif