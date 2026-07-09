#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
private:
    string name;

public:
    Character();
    Character(string n);

    string getName();
    void setName(string n);
    void display();
};

#endif
