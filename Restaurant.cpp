#include "Restaurant.h"
#include <iostream>
using namespace std;

Restaurant::Restaurant() {
    //Default constructor
    name = "";
    unlocked = false;
    competitionDay = 0;
}

Restaurant::Restaurant(string n, bool u, int day) {
    // Parameterized 
    name = n;
    unlocked = u;
    competitionDay = day;
}

//Getter Functions 
string Restaurant::getName() { 
    return name; }
bool Restaurant::getUnlocked() { 
    return unlocked; }
int Restaurant::getCompetitionDay() { 
    return competitionDay; }

//Return the selected food item if the index is valid
Food Restaurant::getFood(int index) {
    if (index < 0 || index >= 4) 
    return Food();
    return foods[index];
}

Rival Restaurant::getRival() { 
    return rival; }

//Lock or unlock the restaurant function
void Restaurant::setUnlocked(bool value) { 
    unlocked = value; }

//Store a food item in the menu 
void Restaurant::setFood(int index, Food food) {
    if (index >= 0 && index < 4) foods[index] = food;
}

//Set a rival to the restaurant for comepeting 
void Restaurant::setRival(Rival r) { 
    rival = r; 
}

void Restaurant::displayFoods(int followers) {
   // Menu Creation
    cout << endl;
    cout << name << " MENU" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 4; i++) { //4 food items
        cout << i + 1 << ". " << foods[i].getName() << endl;
        cout << "   Cost: $" << foods[i].getPrice() << endl;
        //If statement is basically saying: foods in array is unlocked 
        //based on followers
        if (foods[i].isUnlocked(followers)) cout << "   Available" << endl;
        else cout << "   Locked until " << foods[i].getFollowerRequirement() << " followers" << endl;
        cout << endl;
    }
    //Cancel option 
    cout << "5. Cancel" << endl;
}
