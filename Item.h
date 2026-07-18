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
    Item();
    Item(string n, string t, int l);

    string getName();
    string getType();
    int getLevel();
    void setLevel(int l);
};

#endif
