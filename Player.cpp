#include "Player.h"
#include <iostream>

using namespace std;

// Default constructor
Player::Player() {
    name = "";
    currentLocation = "Apartment";

    followers = 0;
    money = 3000;
    dramaPoints = 0;
    actionsRemaining = 3;

    cameraLevel = 1;
    lightingLevel = 1;
    microphoneLevel = 1;

    legitimateWins = 0;
    rivalsBotted = 0;

    inventorySize = 0;

    Item basicCamera("Basic Camera", "Equipment", 1, 0);
    addItem(basicCamera);
}

// Parameterized constructor
Player::Player(string n) {
    name = n;
    currentLocation = "Apartment";

    followers = 0;
    money = 3000;
    dramaPoints = 0;
    actionsRemaining = 3;

    cameraLevel = 1;
    lightingLevel = 1;
    microphoneLevel = 1;

    legitimateWins = 0;
    rivalsBotted = 0;

    inventorySize = 0;

    Item basicCamera("Basic Camera", "Equipment", 1, 0);
    addItem(basicCamera);
}

// Getters
string Player::getName() {
    return name;
}

string Player::getCurrentLocation() {
    return currentLocation;
}

int Player::getFollowers() {
    return followers;
}

int Player::getMoney() {
    return money;
}

int Player::getDramaPoints() {
    return dramaPoints;
}

int Player::getActionsRemaining() {
    return actionsRemaining;
}

int Player::getCameraLevel() {
    return cameraLevel;
}

int Player::getLightingLevel() {
    return lightingLevel;
}

int Player::getMicrophoneLevel() {
    return microphoneLevel;
}

int Player::getLegitimateWins() {
    return legitimateWins;
}

int Player::getRivalsBotted() {
    return rivalsBotted;
}

int Player::getInventorySize() {
    return inventorySize;
}

// Location
void Player::setCurrentLocation(string location) {
    currentLocation = location;
}

// Followers
void Player::addFollowers(int amount) {
    if (amount > 0) {
        followers += amount;
    }
}

void Player::loseFollowers(int amount) {
    if (amount > 0) {
        followers -= amount;

        if (followers < 0) {
            followers = 0;
        }
    }
}

// Money
void Player::addMoney(int amount) {
    if (amount > 0) {
        money += amount;
    }
}

bool Player::spendMoney(int amount) {
    if (amount >= 0 && money >= amount) {
        money -= amount;
        return true;
    }

    return false;
}

// Drama
void Player::addDrama(int amount) {
    if (amount > 0) {
        dramaPoints += amount;
    }
}

void Player::reduceDrama(int amount) {
    if (amount > 0) {
        dramaPoints -= amount;

        if (dramaPoints < 0) {
            dramaPoints = 0;
        }
    }
}

// Actions
void Player::resetActions() {
    actionsRemaining = 3;
}

void Player::useAction() {
    if (actionsRemaining > 0) {
        actionsRemaining--;
    }
}

// Equipment
void Player::upgradeCamera() {
    if (cameraLevel < 3) {
        cameraLevel++;
    }
}

void Player::upgradeLighting() {
    if (lightingLevel < 3) {
        lightingLevel++;
    }
}

void Player::upgradeMicrophone() {
    if (microphoneLevel < 3) {
        microphoneLevel++;
    }
}

// Competition tracking
void Player::addLegitimateWin() {
    legitimateWins++;
}

void Player::addRivalBotted() {
    rivalsBotted++;
}

// Inventory
void Player::addItem(Item newItem) {
    if (inventorySize < 20) {
        inventory[inventorySize] = newItem;
        inventorySize++;
    }
}

bool Player::hasItem(string itemName) {
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].getName() == itemName) {
            return true;
        }
    }

    return false;
}

int Player::countItemsOfType(string itemType) {
    int count = 0;

    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].getType() == itemType) {
            count++;
        }
    }

    return count;
}

void Player::displayInventory() {
    cout << "~~~~~~~~~~ INVENTORY ~~~~~~~~~~" << endl;

    if (inventorySize == 0) {
        cout << "Inventory is empty." << endl;
        return;
    }

    for (int i = 0; i < inventorySize; i++) {
        cout << i + 1 << ") ";
        inventory[i].displayItem();
    }
}