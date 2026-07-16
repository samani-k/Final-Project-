#include "item.h"
#include <iostream> 

using namespace std;
 
//Default Constructor initialized
 Item::Item (){
        name = "";
        type = "";
        level = 0;
        value = 0; 
    }

    //Constructor for all variables initialized
    Item::Item (string n, string t, int l, int v){
        name = n;
        type = t;
        level = l;
        value = v; 
    }

    // Getters
    string Item::getName(){
        return name; 
    }

    string Item::getType(){
        return type;
    }

    int Item::getLevel(){
        return level;
    }

    int Item::getValue(){
        return value; 
    }

//Display Function

void Item::displayItem (){    
    cout << name << " - " << type; 

    // If statement to make sure only levels > 0 print
    if (level > 0){
        cout << " - " << "Level " <<  level << endl; 
    }
    else{
        cout << endl; 

    }
}