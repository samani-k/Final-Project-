#include "Food.h"
#include <iostream> 
#include <string>
using namespace std;

// Default Constructor 
Food::Food() {
    name = "";
    price = 0;
    followerRequirement = 0;
    contentBonus = 0;
}

// Parameterized Constructor
Food::Food(string n, int p, int req, int bonus) {
    name = n;
    price = p;
    followerRequirement = req;
    contentBonus = bonus;
}

// Getters
string Food::getName() { 
    return name; 
}
int Food::getPrice() { 
    return price; 
}
int Food::getFollowerRequirement() { 
    return followerRequirement;
 }
int Food::getContentBonus() { 
    return contentBonus; 
}

// Unlocked Function 
bool Food::isUnlocked(int followers) { 
    return followers >= followerRequirement; }
