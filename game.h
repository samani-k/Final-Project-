#include <string>
#include "Player.h"
#include "Restaurant.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game {
private:
    Player player;
    Restaurant restaurants[4];

    int restaurantCount;
    int currentDay;
    bool gameOver;
    bool playerQuit;

public:
    Game();
    Game(string playerName);

    void setupRestaurants();
    void loadRivals();

    void displayIntroduction();
    void startGame();
    void displayMainMenu();
    void displayMap();
    void handleMainMenuChoice(int choice);

    void travel();
    void createContent();
    void talkToRival();
    void upgradeEquipment();
    void viewStats();
    void visitShadyAgency();
    void endDay();

    void checkCompetition();
    void runCompetition(int restaurantIndex);

    bool checkWin();
    bool checkLoss();
    void displayEnding();

    int getCurrentRestaurantIndex();
    int getRestaurantUnlockRequirement(int restaurantIndex);
    int calculateEquipmentBonus();

    int getCurrentDay();
    bool getGameOver();
};

#endif