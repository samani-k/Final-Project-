#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Restaurant.h"
#include <string>
using namespace std;

class Game {
private:
    Player player;
    Restaurant restaurants[4];
    int restaurantCount;
    int currentDay;
    bool gameOver;
    bool playerQuit;
    bool competitionCompleted[4];
    bool foodUnlockAnnounced[4][4];
    bool restaurantUnlockAnnounced[4];
    bool firstFeeExplained;

    void setupRestaurants();
    void loadRivals();
    void displayIntroduction();
    void displayMainMenu();
    void displayMap();
    void handleMainMenuChoice(int choice);
    void travel();
    void createContent();
    void enterLocation();
    void apartmentMenu();
    void equipmentStore();
    void shadyAgency();
    void viewProfile();
    void endDay();
    void startNewDay();
    void processFees();
    void announceUnlocks();
    void announceCompetitionDay();
    void runCompetition(int index);
    void displayEnding();
    int getCurrentRestaurantIndex();
    int getRestaurantUnlockRequirement(int index);
    int getEquipmentBonus();
    int getContentFollowers(Food food, int contentChoice);
    int getContentMoney(int contentChoice);
    int getLiveDonations();
    string getNextUnlockText();

public:
    Game();
    void startGame();
};
