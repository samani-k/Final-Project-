#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
    name = "";
    followers = 0;
    money = 3000;
    dramaPoints = 0;
    actionsRemaining = 3;
    currentLocation = "Apartment";
    cameraLevel = 1;
    lightingLevel = 0;
    microphoneLevel = 0;
    competitionWins = 0;
    rivalsBanned = 0;
    inventorySize = 0;
    addItem(Item("Basic Camera", "Equipment", 1));
}

Player::Player(string n) {
    name = n;
    followers = 0;
    money = 3000;
    dramaPoints = 0;
    actionsRemaining = 3;
    currentLocation = "Apartment";
    cameraLevel = 1;
    lightingLevel = 0;
    microphoneLevel = 0;
    competitionWins = 0;
    rivalsBanned = 0;
    inventorySize = 0;
    addItem(Item("Basic Camera", "Equipment", 1));
}

string Player::getName() {
     return name; }
int Player::getFollowers() {
     return followers; }
int Player::getMoney() {
     return money; }
int Player::getDramaPoints() {
     return dramaPoints; }
int Player::getActionsRemaining() { 
    return actionsRemaining; }
string Player::getCurrentLocation() { 
    return currentLocation; }
int Player::getCameraLevel() { 
    return cameraLevel; }
int Player::getLightingLevel() {
     return lightingLevel; }
int Player::getMicrophoneLevel() { 
    return microphoneLevel; }
int Player::getCompetitionWins() { 
    return competitionWins; }
int Player::getRivalsBanned() { 
    return rivalsBanned; }
int Player::getInventorySize() { 
    return inventorySize; }

void Player::addFollowers(int amount) { 
    followers += amount; }
void Player::addMoney(int amount) { 
    money += amount; }

bool Player::spendMoney(int amount) {
    if (money < amount) return false;
    money -= amount;
    return true;
}

void Player::addDrama(int amount) {
     dramaPoints += amount; }

void Player::reduceDrama(int amount) {
    dramaPoints -= amount;
    if (dramaPoints < 0) dramaPoints = 0;
}

void Player::useAction() {
    if (actionsRemaining > 0) actionsRemaining--;
}

void Player::resetActions() { 
    actionsRemaining = 3; }
void Player::setCurrentLocation(string location) { 
    currentLocation = location; }

void Player::upgradeCamera() {
    cameraLevel++;
    inventory[0].setLevel(cameraLevel);
}

void Player::upgradeLighting() {
    lightingLevel++;
    if (lightingLevel == 1) addItem(Item("Studio Lighting", "Equipment", 1));
    else {
        for (int i = 0; i < inventorySize; i++) {
            if (inventory[i].getName() == "Studio Lighting") inventory[i].setLevel(lightingLevel);
        }
    }
}

void Player::upgradeMicrophone() {
    microphoneLevel++;
    if (microphoneLevel == 1) addItem(Item("External Microphone", "Equipment", 1));
    else {
        for (int i = 0; i < inventorySize; i++) {
            if (inventory[i].getName() == "External Microphone") inventory[i].setLevel(microphoneLevel);
        }
    }
}

void Player::addCompetitionWin() { competitionWins++; }
void Player::addRivalBanned() { rivalsBanned++; }

void Player::addItem(Item item) {
    if (inventorySize < 12) {
        inventory[inventorySize] = item;
        inventorySize++;
    }
}

void Player::displayInventory() {
    cout << "Inventory:" << endl;
    if (inventorySize == 0) cout << "- Empty" << endl;
    for (int i = 0; i < inventorySize; i++) {
        cout << "- " << inventory[i].getName();
        if (inventory[i].getType() == "Equipment") {
            cout << " - Level " << inventory[i].getLevel();
        }
        cout << endl;
    }
}
