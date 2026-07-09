#include "Restaurant.h"
#include <iostream>
using namespace std;

Restaurant::Restaurant() {
    name = "";
    followersGiven = 0;
}

Restaurant::Restaurant(string n, int f) {
    name = n;
    followersGiven = f;
}

string Restaurant::getName() {
    return name;
}

int Restaurant::getFollowersGiven() {
    return followersGiven;
}

void Restaurant::display() {
    cout << name << " gives " << followersGiven << " followers per video." << endl;
}
