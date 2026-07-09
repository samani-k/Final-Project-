#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
using namespace std;

class Restaurant {
private:
    string name;
    int followersGiven;

public:
    Restaurant();
    Restaurant(string n, int f);

    string getName();
    int getFollowersGiven();

    void display();
};

#endif
