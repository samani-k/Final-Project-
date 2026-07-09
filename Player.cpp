#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() : Character("Player") {
    followers = 0;
    money = 100;
    location = "Home";
}

int Player::getFollowers() {
    return followers;
}

int Player::getMoney() {
    return money;
}

string Player::getLocation() {
    return location;
}

void Player::addFollowers(int amount) {
    followers += amount;
}

void Player::addMoney(int amount) {
    money += amount;
}

void Player::moveTo(string newLocation) {
    location = newLocation;
}

void Player::displayStats() {
    cout << "Followers: " << followers << endl;
    cout << "Money: $" << money << endl;
    cout << "Location: " << location << endl;
}
