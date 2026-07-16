#include "Food.h"
#include <iostream> 
#include <string>
using namespace std;

// Default Constructor 
Food:: Food (){
        name = "";
        price = 0;
        followerReq = 0;
        contentBonus = 0; 
}

// Parameterized Constructor
Food::Food (string n, int p, int f, int c){
        name = n;
        price = p;
        followerReq = f;
        contentBonus = c;
}

// Getters
string Food::getName(){
    return name;
}

int Food::getPrice(){
    return price;
}

int Food::getfollowerReq(){
    return followerReq;
}

int Food::getcontentBonus(){
    return contentBonus; 
}

//Unlocked Function
bool Food::isUnlocked(int playerFollowers){
    if (playerFollowers >= followerReq){
        return true;
    }else{
        return false; 
    }
}

//Display Function

void Food::displayFood (){
    cout << name << "($" << price << "): " << endl;
    cout << "- Requires: " << followerReq << " followers" << endl;
    cout << "- Bonus: " << contentBonus << " followers" << endl; 
}


