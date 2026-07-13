#include "Game.h"
#include <iostream>
#include <fstream> 
using namespace std;

Game::Game() {
    player = Player();
    restaurant = Restaurant("Burger Barn", 50);
    running = true;
}

bool Game::loadRestaurant(string filename) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Could not open restaurant file." << endl;
        return false;
    }

    string restaurantName;
    int followers;

    getline(inputFile, restaurantName);
    inputFile >> followers;

    restaurant = Restaurant(restaurantName, followers);

    inputFile.close();

    return true;
}

void Game::start() {
    while (running) {
        showMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            showStats();
        }
        else if (choice == 2) {
            travel();
        }
        else if (choice == 3) {
            film();
        }
        else if (choice == 4) {
            running = false;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
}

void Game::showMenu() {
    cout << endl;
    cout << "===== MukHouse =====" << endl;
    cout << "1. Show Stats" << endl;
    cout << "2. Travel" << endl;
    cout << "3. Film Video" << endl;
    cout << "4. Quit" << endl;
    cout << "Choice: ";
}

void Game::showStats() {
    player.displayStats();
}

void Game::travel() {
    player.moveTo(restaurant.getName());
    cout << "You traveled to " << restaurant.getName() << "." << endl; 
}

void Game::film() {
if (player.getLocation() == restaurant.getName()) {        player.addFollowers(restaurant.getFollowersGiven());
        player.addMoney(25);
        cout << "You filmed a mukbang video!" << endl;
        cout << "You gained followers and money." << endl;
    }
    else {
        cout << "You need to travel to a restaurant first." << endl;
    }
}
