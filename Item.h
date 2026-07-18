#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
private:
    string name;
    string type;
    int level;

public:
// Default Constructor
    Item();
// Parameterized Constructor 
    Item(string n, string t, int l);

//Getters
    string getName();
    string getType();
    int getLevel();
//Method to set upgrade level of inventory item 
    void setLevel(int l);
};

#endif
