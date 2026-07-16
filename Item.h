//Home of Permanent Inventory Items 
#include <string>
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
    private:
    string name; 
    string type; //Organization of Inventory items
    int level;
    int value; 

    public: 
    //Default Constructor
    Item ();

    //Constructor for all variables 
    Item (string n, string t, int l, int v); 
    
    // Getters
    string getName();
    string getType();
    int getLevel();
    int getValue(); 

    //Display Function
    void displayItem (); 
}; 

#endif 