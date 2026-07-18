#include "Item.h"

Item::Item() {
    name = "";
    type = "";
    level = 0;
}

Item::Item(string n, string t, int l) {
    name = n;
    type = t;
    level = l;
}

string Item::getName() { 
    return name; }
string Item::getType() { 
    return type; }
int Item::getLevel() { 
    return level; }
void Item::setLevel(int l) { 
    level = l; }
