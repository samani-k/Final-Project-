#include "Restaurant.h"
#include <iostream>
using namespace std;

Restaurant::Restaurant() {
    name = "";
    unlocked = false;
    competitionDay = 0;
}

Restaurant::Restaurant(string n, bool u, int day) {
    name = n;
    unlocked = u;
    competitionDay = day;
}

string Restaurant::getName() { return name; }
bool Restaurant::getUnlocked() { return unlocked; }
int Restaurant::getCompetitionDay() { return competitionDay; }

Food Restaurant::getFood(int index) {
    if (index < 0 || index >= 4) return Food();
    return foods[index];
}

Rival Restaurant::getRival() { return rival; }
void Restaurant::setUnlocked(bool value) { unlocked = value; }

void Restaurant::setFood(int index, Food food) {
    if (index >= 0 && index < 4) foods[index] = food;
}

void Restaurant::setRival(Rival r) { rival = r; }

void Restaurant::displayFoods(int followers) {
    cout << endl;
    cout << name << " MENU" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << foods[i].getName() << endl;
        cout << "   Cost: $" << foods[i].getPrice() << endl;
        if (foods[i].isUnlocked(followers)) cout << "   Available" << endl;
        else cout << "   Locked until " << foods[i].getFollowerRequirement() << " followers" << endl;
        cout << endl;
    }
    cout << "5. Cancel" << endl;
}
