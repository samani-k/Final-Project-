#include <string>
#ifndef FOOD_H
#define FOOD_H

using namespace std;  

class Food {
    private:
    string name; 
    int price;
    int followerReq;
    int contentBonus;

    public:
    //Default Constructor
    Food ();      

    //Parameterized Constructor
    Food (string n, int p, int f, int c); 

    // Getters
   string getName(); 
   int getPrice();
   int getfollowerReq();
   int getcontentBonus();

   bool isUnlocked(int playerFollowers);
   void displayFood();

};
#endif