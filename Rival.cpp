#include <iostream>
#include <string> 
#include "Rival.h"

using namespace std;

// Default
Rival::Rival () : Character (){
        skillLevel = 0;
        banned = false;
        defeated = false;
    }
// Parameterized
Rival::Rival (string n, string l, string r, string d, int s)
// Inheritance
: Character (n,l,r,d){
        skillLevel = s;
        banned = false;
        defeated = false; 
    }

    // Getters

    int Rival:: getskillLevel(){
        return skillLevel; 
    }
    bool Rival:: getBanned(){
        return banned;
    }
    bool Rival:: getDefeated(){
        return defeated; 
    }

    // Setters
   void Rival:: setBanned (bool status){
        banned = status;
   }
   void Rival:: setDefeated (bool status){
        defeated = status; 
   }

    // Display Function

    void Rival:: displayRival(){
    cout << getName() << "(" << getRole() << ")" << endl;
    cout << "Restaurant: " << getLocation() << endl;
    cout << "Social Media Influence: " << skillLevel << endl;
        
        if (banned){
            cout << "Status: Banned" << endl;
        } 
        else if (defeated){
            cout << "Status: Defeated" << endl;
        }
        else {
            cout << "Status: Active" << endl; 
        }    
    }
