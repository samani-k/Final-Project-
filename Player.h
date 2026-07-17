#include <string>
#include <iostream> 
#include "Item.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
    private:
    string name;
    string currentLocation;
    
    int followers;
    int money;
    int dramaPoints;
    int actionsRemaining;

    int cameraLevel;
    int lightingLevel;
    int microphoneLevel;

    int legitimateWins;
    int rivalsBotted;

    Item inventory[20];
    int inventorySize; 

    public:
    // Constructors
    Player();
    Player(string n);

    // Getters
    string getName();
    string getCurrentLocation();

    int getFollowers();
    int getMoney();
    int getDramaPoints();
    int getActionsRemaining();

    int getCameraLevel();
    int getLightingLevel();
    int getMicrophoneLevel();

    int getLegitimateWins();
    int getRivalsBotted();
    int getInventorySize();

   // Location
    void setCurrentLocation(string location);

    // Followers
    void addFollowers(int amount);
    void loseFollowers(int amount);

    // Money
    void addMoney(int amount);
    bool spendMoney(int amount);

    // Drama
    void addDrama(int amount);
    void reduceDrama(int amount);

    // Actions
    void resetActions();
    void useAction();

    // Equipment
    void upgradeCamera();
    void upgradeLighting();
    void upgradeMicrophone();

    // Competition tracking
    void addLegitimateWin();
    void addRivalBotted();

    // Inventory
    void addItem(Item newItem);
    bool hasItem(string itemName);
    int countItemsOfType(string itemType);
    void displayInventory();

};
#endif