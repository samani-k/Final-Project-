#include "Item.h"

//Default
Item::Item() {
    name = "";
    type = "";
    level = 0;
}

//Parameterized 
Item::Item(string n, string t, int l) {
    name = n;
    type = t;
    level = l;
}

//Getters
string Item::getName() { 
    return name; }
string Item::getType() { 
    return type; }
int Item::getLevel() { 
    return level; }

    //Setter
void Item::setLevel(int l) { 
    level = l; }
