#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"
#include <string>
using namespace std;

class Player {
private:
    string name;
    int followers;
    int money;
    int dramaPoints;
    int actionsRemaining;
    string currentLocation;
    int cameraLevel;
    int lightingLevel;
    int microphoneLevel;
    int competitionWins;
    int rivalsBanned;
    Item inventory[12];
    int inventorySize;

public:
    Player();
    Player(string n);

    string getName();
    int getFollowers();
    int getMoney();
    int getDramaPoints();
    int getActionsRemaining();
    string getCurrentLocation();
    int getCameraLevel();
    int getLightingLevel();
    int getMicrophoneLevel();
    int getCompetitionWins();
    int getRivalsBanned();
    int getInventorySize();

    void addFollowers(int amount);
    void addMoney(int amount);
    bool spendMoney(int amount);
    void addDrama(int amount);
    void reduceDrama(int amount);
    void useAction();
    void resetActions();
    void setCurrentLocation(string location);
    void upgradeCamera();
    void upgradeLighting();
    void upgradeMicrophone();
    void addCompetitionWin();
    void addRivalBanned();
    void addItem(Item item);
    void displayInventory();
};

#endif
