#include <string>
#include <iostream>
#include "Restaurant.h"

using namespace std;

    Restaurant::Restaurant (){
        // All new variables, rest are already default constructed from their .h file
        name = "";
        unlocked = false;
        playerFeatured = false;
        competitionCompleted = false; 
        competitionDay = 0; 
    }

    Restaurant::Restaurant (string n, bool u, int cd){
        name = n;
        unlocked = u;
        competitionDay = cd; 
        playerFeatured = false;
        competitionCompleted = false; 
    }

//Getters
string Restaurant::getName(){
    return name;
}
bool Restaurant::getUnlocked(){
    return unlocked;
}
bool Restaurant::getplayerFeatured(){
    return playerFeatured;
}
bool Restaurant::getcompetitionCompleted(){
    return competitionCompleted;
}
int Restaurant::getcompetitionDay(){
    return competitionDay;
}
Rival Restaurant::getRival(){
    return rival;
}
Food Restaurant::getFood(int ind){
    if (ind >= 0 && ind < 4){
        return foods[ind];
    }

   //to account for user inputs that are not between 0 and 3
   //Calls the default constructor 
   return Food();
}
    
// Setters
    void Restaurant::setUnlocked(bool status){
        unlocked = status;
    }
    void Restaurant::setplayerFeatured(bool status){
        playerFeatured = status;
    }
    void Restaurant::setcompetitionCompleted (bool status){
        competitionCompleted = status; 
    }

    void Restaurant::setRival(Rival r){
        rival = r; 
    }
    void Restaurant::setFood(int ind, Food newFood){
       if (ind >= 0 && ind < 4){
        foods[ind] = newFood; 
       }
    }

// Methods

//Counts how many foods in a restaurant a player has unlocked
int Restaurant::countUnlockedFoods (int playerFollowers){
    int count = 0;
    for (int i = 0; i < 4; i++){
        if (foods[i].isUnlocked(playerFollowers) ){
            count++;
        }
    }
    return count; 
}

//Displays the four restaurant foods
void Restaurant::displayFoods(int playerFollowers) {
    cout << "========== " << name << " ==========" << endl;

    for (int i = 0; i < 4; i++) {
        cout << endl;
        cout << i + 1 << ") ";
        foods[i].displayFood();

        cout << "   Unlock: "
             << foods[i].getfollowerReq()
             << " followers" << endl;

        cout << "   Follower Bonus: +"
             << foods[i].getcontentBonus()
             << endl;

        if (foods[i].isUnlocked(playerFollowers)) {
            cout << "   Status: UNLOCKED" << endl;
        }
        else {
            cout << "   Status: LOCKED" << endl;
        }
    }
}

void Restaurant::displayRestaurant(){
    cout << "========" << name << "========" << endl;

    if (unlocked) {
        cout << "Status: Unlocked" << endl;
    }
    else {
        cout << "Status: Locked" << endl;
    }

    cout << "Competition Day: " << competitionDay << endl;
    cout << "Rival: " << rival.getName() << endl;

    if (playerFeatured) {
        cout << "Featured Creator: Player" << endl;
    }
    else {
        cout << "Featured Creator: " << rival.getName() << endl;
    }

    if (competitionCompleted) {
        cout << "Competition: Completed" << endl;
    }
    else {
        cout << "Competition: Not Completed" << endl;
    }
}

