#include <string>
#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;


class Character {
private:
    string name;
    string role;

public:
    // Constructors
    Character();
    Character(string n,string r);

    // Getters
    string getName();
    string getRole();


    // Display functions
    void setName (string n);
    void setRole (string r);
    virtual void talk();
    // Virtual makes it so the program looks at the object and runs the code that matches up correctly
};



#endif