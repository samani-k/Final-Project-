#include "Game.h"

#include <fstream>
#include <iostream>

using namespace std;

// Constructors
Game::Game() {
    player = Player();
    restaurantCount = 4;
    currentDay = 1;
    gameOver = false;
    playerQuit = false;

    setupRestaurants();
    loadRivals();
}

Game::Game(string playerName) {
    player = Player(playerName);
    restaurantCount = 4;
    currentDay = 1;
    gameOver = false;
    playerQuit = false;

    setupRestaurants();
    loadRivals();
}

// Creates the four restaurants and their food menus.
void Game::setupRestaurants() {
    restaurants[0] = Restaurant("Raising Cane's", true, 5);
    restaurants[0].setFood(0, Food("Three Finger Combo", 10, 0, 5000));
    restaurants[0].setFood(1, Food("Box Combo", 14, 10000, 8000));
    restaurants[0].setFood(2, Food("Caniac Combo", 18, 25000, 12000));
    restaurants[0].setFood(3, Food("Tailgate Feast", 35, 40000, 18000));

    restaurants[1] = Restaurant("In-N-Out", false, 10);
    restaurants[1].setFood(0, Food("Cheeseburger", 7, 50000, 12000));
    restaurants[1].setFood(1, Food("Animal Style Fries", 6, 70000, 16000));
    restaurants[1].setFood(2, Food("Double-Double", 11, 90000, 22000));
    restaurants[1].setFood(3, Food("Four-by-Four", 16, 120000, 30000));

    restaurants[2] = Restaurant("El Pollo Loco", false, 15);
    restaurants[2].setFood(0, Food("BRC Burrito Meal", 10, 150000, 22000));
    restaurants[2].setFood(1, Food("Chicken Tostada", 13, 175000, 28000));
    restaurants[2].setFood(2, Food("Three-Piece Meal", 15, 200000, 35000));
    restaurants[2].setFood(3, Food("Family Chicken Feast", 30, 250000, 45000));

    restaurants[3] = Restaurant("Hot Pot", false, 20);
    restaurants[3].setFood(0, Food("Vegetable Hot Pot", 18, 300000, 35000));
    restaurants[3].setFood(1, Food("Beef Hot Pot", 25, 340000, 45000));
    restaurants[3].setFood(2, Food("Seafood Hot Pot", 32, 380000, 55000));
    restaurants[3].setFood(3, Food("Ultimate Hot Pot Feast", 50, 420000, 70000));
}

// Reads one rival for each restaurant from Rivals.txt.
void Game::loadRivals() {
    ifstream inputFile("Rivals.txt");

    if (!inputFile.is_open()) {
        cout << "Error: Rivals.txt could not be opened." << endl;
        gameOver = true;
        return;
    }

    for (int i = 0; i < restaurantCount; i++) {
        string name;
        string location;
        string role;
        string dialogue;
        int skill;

        getline(inputFile, name);
        getline(inputFile, location);
        getline(inputFile, role);
        getline(inputFile, dialogue);
        inputFile >> skill;
        inputFile.ignore();

        restaurants[i].setRival(
            Rival(name, location, role, dialogue, skill)
        );
    }

    inputFile.close();
}

// Displays the story before the game.
void Game::displayIntroduction() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "              MUKBANG CITY              " << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << "A few months ago, you unexpectedly lost your job."
         << endl;

    cout << "Since then, your savings have been disappearing"
         << endl;

    cout << "faster than you expected." << endl;

    cout << endl;

    cout << "One afternoon, your phone rings." << endl;

    cout << "It is your old friend Mia, who now works as a"
         << endl;

    cout << "creator manager in Mukbang City." << endl;

    cout << endl;

    cout << "\"I need a new client,\" Mia tells you." << endl;

    cout << "\"Mukhouse, the biggest mukbang content creation house applications are opening, and I think"
         << endl;

    cout << "you could become the city's next mukbang star.\""
         << endl;

    cout << endl;

    cout << "Mia offers to manage your career and help you"
         << endl;

    cout << "build a following before applications close."
         << endl;

    cout << endl;

    cout << "Do you accept Mia's offer?" << endl;
}

// Starts the game and controls the main loop.
void Game::startGame() {
    if (gameOver) {
        cout << "The game cannot begin without Rivals.txt." << endl;
        return;
    }

    displayIntroduction();

    char beginChoice;

    cout << "Enter y to accept or n to decline: ";
    cin >> beginChoice;

    if (beginChoice == 'n' || beginChoice == 'N') {
        playerQuit = true;
        gameOver = true;

        cout << endl;
        cout << "You decide that becoming a mukbang creator"
             << endl;

        cout << "is not the right path for you."
             << endl;

        cout << endl;
        cout << "GAME ENDED" << endl;

        return;
    }

    if (beginChoice != 'y' && beginChoice != 'Y') {
        cout << "Invalid choice. Please restart the game."
             << endl;

        playerQuit = true;
        gameOver = true;
        return;
    }

    string playerName;

    cout << endl;
    cout << "\"Perfect! First, we need your" << endl;

    cout << "creator name.\"" << endl;

    cout << endl;
    cout << "Enter your creator username: ";
    cin >> playerName;

    player = Player(playerName);

    cout << endl;
    cout << "\"Welcome to Mukbang City, "
         << player.getName() << "!\"" << endl;

    cout << endl;
    cout << "Mia explains the goal:" << endl;

    cout << endl;
    cout << "- You have 28 days until the application is due." << endl;
    cout << "- You need 500,000 followers minimum to apply to the MukHouse." << endl;
    cout << "- I'll lend you $3000." << endl;
    cout << "- You receive 3 actions each day." << endl;

    cout << endl;
    cout << "You will travel to restaurants, purchase food,"
         << endl;

    cout << "create content, upgrade your equipment, and"
         << endl;

    cout << "compete against each restaurant's featured"
         << endl;

    cout << "creator." << endl;

    cout << endl;
    cout << "Mia gives you one final warning:" << endl;

    cout << endl;
    cout << "\"There is a Shady Creator Agency in the city."
         << endl;

    cout << "They can help you grow faster, but every shady"
         << endl;

    cout << "choice increases your Drama Points. Reach 100"
         << endl;

    cout << "Drama Points and your career is over.\"" << endl;

    cout << endl;
    cout << "Your journey begins at your apartment." << endl;

    while (!gameOver) {
        displayMainMenu();

        int choice;
        cin >> choice;

        handleMainMenuChoice(choice);

        if (checkWin() || checkLoss()) {
            gameOver = true;
        }
    }

    displayEnding();
}

// Displays a simple location map and marks the player with an asterisk.
void Game::displayMap() {
    cout << endl;
    cout << "Map:" << endl;

    if (player.getCurrentLocation() == "Apartment") {
        cout << "[*Apartment]";
    }
    else {
        cout << "[Apartment]";
    }

    cout << " -- ";

    for (int i = 0; i < restaurantCount; i++) {
        if (player.getCurrentLocation() == restaurants[i].getName()) {
            cout << "[*" << restaurants[i].getName() << "]";
        }
        else if (player.getFollowers()
                 < getRestaurantUnlockRequirement(i)) {
            cout << "[LOCKED]";
        }
        else {
            cout << "[" << restaurants[i].getName() << "]";
        }

        if (i < restaurantCount - 1) {
            cout << " -- ";
        }
    }

    cout << endl;
    cout << "* = current location" << endl;
}

// Displays the dashboard and menu.
void Game::displayMainMenu() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "DAY " << currentDay << " OF 28" << endl;
    cout << "========================================" << endl;
    cout << "Location: " << player.getCurrentLocation() << endl;
    cout << "Followers: " << player.getFollowers() << " / 500000" << endl;
    cout << "Money: $" << player.getMoney() << endl;
    cout << "Drama: " << player.getDramaPoints() << " / 100" << endl;
    cout << "Actions Remaining: " << player.getActionsRemaining() << endl;
    cout << "Inventory Items: " << player.getInventorySize() << endl;

    displayMap();

    cout << endl;
    cout << "1. Travel" << endl;
    cout << "2. Create Mukbang Content" << endl;
    cout << "3. Talk to Featured Creator" << endl;
    cout << "4. Upgrade Equipment" << endl;
    cout << "5. View Stats" << endl;
    cout << "6. View Inventory" << endl;
    cout << "7. Visit Shady Creator Agency" << endl;
    cout << "8. End Day" << endl;
    cout << "9. Quit Game" << endl;
    cout << "Choose an option: ";
}

void Game::handleMainMenuChoice(int choice) {
    if (choice == 1) {
        travel();
    }
    else if (choice == 2) {
        createContent();
    }
    else if (choice == 3) {
        talkToRival();
    }
    else if (choice == 4) {
        upgradeEquipment();
    }
    else if (choice == 5) {
        viewStats();
    }
    else if (choice == 6) {
        player.displayInventory();
    }
    else if (choice == 7) {
        visitShadyAgency();
    }
    else if (choice == 8) {
        endDay();
    }
    else if (choice == 9) {
        char quitChoice;
        cout << "Are you sure you want to quit? (y/n): ";
        cin >> quitChoice;

        if (quitChoice == 'y' || quitChoice == 'Y') {
            playerQuit = true;
            gameOver = true;
        }
    }
    else {
        cout << "Invalid menu choice." << endl;
    }
}

int Game::getCurrentRestaurantIndex() {
    for (int i = 0; i < restaurantCount; i++) {
        if (player.getCurrentLocation() == restaurants[i].getName()) {
            return i;
        }
    }

    return -1;
}

int Game::getRestaurantUnlockRequirement(int restaurantIndex) {
    int requirements[4] = {0, 50000, 150000, 300000};
    return requirements[restaurantIndex];
}

void Game::travel() {
    if (player.getActionsRemaining() == 0) {
        cout << "You have no actions remaining today." << endl;
        return;
    }

    cout << endl;
    cout << "=============== TRAVEL ===============" << endl;
    cout << "1. Apartment" << endl;

    for (int i = 0; i < restaurantCount; i++) {
        cout << i + 2 << ". " << restaurants[i].getName();

        if (player.getFollowers() < getRestaurantUnlockRequirement(i)) {
            cout << " [LOCKED: "
                 << getRestaurantUnlockRequirement(i)
                 << " followers]";
        }

        cout << endl;
    }

    int choice;
    cout << "Choose a location: ";
    cin >> choice;

    if (choice == 1) {
        player.setCurrentLocation("Apartment");
        player.useAction();
        cout << "You traveled to your apartment." << endl;
        return;
    }

    int index = choice - 2;

    if (index < 0 || index >= restaurantCount) {
        cout << "Invalid location." << endl;
        return;
    }

    if (player.getFollowers() < getRestaurantUnlockRequirement(index)) {
        cout << "That restaurant is locked." << endl;
        return;
    }

    restaurants[index].setUnlocked(true);
    player.setCurrentLocation(restaurants[index].getName());
    player.useAction();

    cout << "You traveled to " << restaurants[index].getName() << "." << endl;
}

int Game::calculateEquipmentBonus() {
    int extraLevels = player.getCameraLevel()
                    + player.getLightingLevel()
                    + player.getMicrophoneLevel() - 3;

    return extraLevels * 2000;
}

void Game::createContent() {
    if (player.getActionsRemaining() == 0) {
        cout << "You have no actions remaining today." << endl;
        return;
    }

    int index = getCurrentRestaurantIndex();

    if (index == -1) {
        cout << "Travel to a restaurant before creating content." << endl;
        return;
    }

    restaurants[index].displayFoods(player.getFollowers());

    int foodChoice;
    cout << "Choose a food from 1 to 4: ";
    cin >> foodChoice;

    Food food = restaurants[index].getFood(foodChoice - 1);

    if (food.getName() == "") {
        cout << "Invalid food choice." << endl;
        return;
    }

    if (!food.isUnlocked(player.getFollowers())) {
        cout << "That food is still locked." << endl;
        return;
    }

    cout << endl;
    cout << "1. YouTube Mukbang" << endl;
    cout << "2. TikTok Mukbang" << endl;
    cout << "3. Live Stream Mukbang" << endl;

    int contentChoice;
    cout << "Choose a content type: ";
    cin >> contentChoice;

    int multiplier = 0;
    int moneyEarned = 0;
    string contentName = "";

    if (contentChoice == 1) {
        multiplier = 2;
        moneyEarned = 500;
        contentName = "YouTube Mukbang";
    }
    else if (contentChoice == 2) {
        multiplier = 1;
        moneyEarned = 300;
        contentName = "TikTok Mukbang";
    }
    else if (contentChoice == 3) {
        multiplier = 3;
        moneyEarned = 700;
        contentName = "Live Stream Mukbang";
    }
    else {
        cout << "Invalid content choice." << endl;
        return;
    }

    if (!player.spendMoney(food.getPrice())) {
        cout << "You cannot afford that food." << endl;
        return;
    }

    int followersEarned =
        food.getcontentBonus() * multiplier
        + calculateEquipmentBonus();

    player.addFollowers(followersEarned);
    player.addMoney(moneyEarned);
    player.useAction();

    cout << "You posted a " << contentName
         << " featuring " << food.getName() << "." << endl;
    cout << "Followers earned: " << followersEarned << endl;
    cout << "Money earned: $" << moneyEarned << endl;
}

// Lets the player interact with the four rival Character objects.
void Game::talkToRival() {
    if (player.getActionsRemaining() == 0) {
        cout << "You have no actions remaining today." << endl;
        return;
    }

    int index = getCurrentRestaurantIndex();

    if (index == -1) {
        cout << "There is no featured creator at the apartment." << endl;
        return;
    }

    Rival rival = restaurants[index].getRival();
    rival.talk();
    rival.displayRival();

    cout << "Talking to the rival used 1 action." << endl;
    player.useAction();
}

void Game::upgradeEquipment() {
    if (player.getActionsRemaining() == 0) {
        cout << "You have no actions remaining today." << endl;
        return;
    }

    cout << endl;
    cout << "========== EQUIPMENT SHOP ==========" << endl;
    cout << "1. Camera - Level " << player.getCameraLevel() << endl;
    cout << "2. Lighting - Level " << player.getLightingLevel() << endl;
    cout << "3. Microphone - Level " << player.getMicrophoneLevel() << endl;
    cout << "Each upgrade costs $1000. Maximum level: 3." << endl;

    int choice;
    cout << "Choose an upgrade: ";
    cin >> choice;

    int level = 0;

    if (choice == 1) {
        level = player.getCameraLevel();
    }
    else if (choice == 2) {
        level = player.getLightingLevel();
    }
    else if (choice == 3) {
        level = player.getMicrophoneLevel();
    }
    else {
        cout << "Invalid choice." << endl;
        return;
    }

    if (level == 3) {
        cout << "That equipment is already Level 3." << endl;
        return;
    }

    if (!player.spendMoney(1000)) {
        cout << "You do not have enough money." << endl;
        return;
    }

    string itemName;

    if (choice == 1) {
        player.upgradeCamera();
        level = player.getCameraLevel();
        itemName = "Camera Upgrade";
    }
    else if (choice == 2) {
        player.upgradeLighting();
        level = player.getLightingLevel();
        itemName = "Lighting Upgrade";
    }
    else {
        player.upgradeMicrophone();
        level = player.getMicrophoneLevel();
        itemName = "Microphone Upgrade";
    }

    player.addItem(Item(itemName, "Equipment", level, 1000));
    player.useAction();

    cout << itemName << " purchased. New level: " << level << endl;
}

void Game::viewStats() {
    cout << endl;
    cout << "============== PLAYER STATS ==============" << endl;
    cout << "Creator: " << player.getName() << endl;
    cout << "Day: " << currentDay << " / 28" << endl;
    cout << "Location: " << player.getCurrentLocation() << endl;
    cout << "Followers: " << player.getFollowers() << " / 500000" << endl;
    cout << "Money: $" << player.getMoney() << endl;
    cout << "Drama Points: " << player.getDramaPoints() << " / 100" << endl;
    cout << "Actions Remaining: " << player.getActionsRemaining() << endl;
    cout << "Camera Level: " << player.getCameraLevel() << endl;
    cout << "Lighting Level: " << player.getLightingLevel() << endl;
    cout << "Microphone Level: " << player.getMicrophoneLevel() << endl;
    cout << "Featured Badges: " << player.countItemsOfType("Badge") << endl;
    cout << "Legitimate Wins: " << player.getLegitimateWins() << endl;
    cout << "Rivals Botted: " << player.getRivalsBotted() << endl;
}

void Game::visitShadyAgency() {
    if (player.getActionsRemaining() == 0) {
        cout << "You have no actions remaining today." << endl;
        return;
    }

    cout << endl;
    cout << "A shady agent leans across the desk." << endl;
    cout << "\"Why work harder when we can make you look famous today?\"" << endl;
    cout << "1. Buy 20,000 fake followers ($500, +10 Drama)" << endl;
    cout << "2. Bot the current rival ($1000, +20 Drama)" << endl;
    cout << "3. Fake a viral trend (+50,000 followers, +30 Drama)" << endl;
    cout << "4. Leave" << endl;

    int choice;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        if (!player.spendMoney(500)) {
            cout << "You do not have enough money." << endl;
            return;
        }

        player.addFollowers(20000);
        player.addDrama(10);
        player.useAction();
        cout << "The fake followers appear overnight." << endl;
    }
    else if (choice == 2) {
        int index = getCurrentRestaurantIndex();

        if (index == -1) {
            cout << "Travel to a restaurant first." << endl;
            return;
        }

        Rival rival = restaurants[index].getRival();

        if (rival.getBanned()) {
            cout << "That rival is already banned." << endl;
            return;
        }

        if (!player.spendMoney(1000)) {
            cout << "You do not have enough money." << endl;
            return;
        }

        rival.setBanned(true);
        restaurants[index].setRival(rival);
        player.addRivalBotted();
        player.addDrama(20);
        player.useAction();

        cout << rival.getName() << " has been botted and banned." << endl;
    }
    else if (choice == 3) {
        player.addFollowers(50000);
        player.addDrama(30);
        player.useAction();
        cout << "The fake trend goes viral." << endl;
    }
    else if (choice == 4) {
        cout << "\"Come back when you are ready to get serious,\""
             << " the agent says." << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

void Game::endDay() {
    cout << endl;
    cout << "Day " << currentDay << " has ended." << endl;

    checkCompetition();

    if (currentDay % 7 == 0) {
        cout << "Mia calls about your $1200 weekly rent and manager fee." << endl;

        if (player.spendMoney(1200)) {
            cout << "\"Payment received. Keep growing,\" Mia says." << endl;
        }
        else {
            player.addDrama(15);
            cout << "\"Missing payments make us look bad,\" Mia warns." << endl;
            cout << "Drama increased by 15." << endl;
        }
    }

    currentDay++;
    player.resetActions();
}

// Uses each restaurant's stored competition day.
void Game::checkCompetition() {
    for (int i = 0; i < restaurantCount; i++) {
        if (currentDay == restaurants[i].getcompetitionDay()) {
            runCompetition(i);
        }
    }
}

void Game::runCompetition(int restaurantIndex) {
    Rival rival = restaurants[restaurantIndex].getRival();

    cout << endl;
    cout << "========== FEATURED CREATOR CONTEST ==========" << endl;
    cout << "Restaurant: " << restaurants[restaurantIndex].getName() << endl;
    cout << "Opponent: " << rival.getName() << endl;
    rival.talk();

    if (rival.getBanned()) {
        cout << rival.getName() << " is banned, so you win automatically." << endl;
        restaurants[restaurantIndex].setplayerFeatured(true);
        restaurants[restaurantIndex].setcompetitionCompleted(true);
        return;
    }

    char choice;
    cout << "Would you like to compete? (y/n): ";
    cin >> choice;

    if (choice == 'n' || choice == 'N') {
        cout << "You declined the competition." << endl;
        restaurants[restaurantIndex].setcompetitionCompleted(true);
        return;
    }

    int playerScore =
        player.getFollowers() / 5000
        + player.getCameraLevel() * 5
        + player.getLightingLevel() * 5
        + player.getMicrophoneLevel() * 5
        + player.countItemsOfType("Badge") * 5
        - player.getDramaPoints();

    int rivalScore = rival.getskillLevel();

    cout << "Your score: " << playerScore << endl;
    cout << rival.getName() << "'s score: " << rivalScore << endl;

    if (playerScore >= rivalScore) {
        cout << "You won the competition!" << endl;

        player.addFollowers(25000);
        player.addMoney(1000);
        player.addLegitimateWin();

        rival.setDefeated(true);
        restaurants[restaurantIndex].setRival(rival);
        restaurants[restaurantIndex].setplayerFeatured(true);

        player.addItem(
            Item(
                restaurants[restaurantIndex].getName()
                    + " Featured Creator Badge",
                "Badge",
                0,
                0
            )
        );

        cout << "Reward: 25,000 followers, $1000, and a badge." << endl;
    }
    else {
        cout << "You lost and lost 10,000 followers." << endl;
        player.loseFollowers(10000);
    }

    restaurants[restaurantIndex].setcompetitionCompleted(true);
}

bool Game::checkWin() {
    return player.getFollowers() >= 500000;
}

bool Game::checkLoss() {
    return currentDay > 28 || player.getDramaPoints() >= 100;
}

void Game::displayEnding() {
    cout << endl;
    cout << "========================================" << endl;

    if (playerQuit) {
        cout << "GAME ENDED" << endl;
        cout << "You ended your creator journey early." << endl;
    }
    else if (checkWin()) {
        cout << "YOU WIN!" << endl;
        cout << "Mukhouse accepts your application." << endl;

        if (player.getDramaPoints() == 0) {
            cout << "You became a star without using shady shortcuts." << endl;
        }
        else if (player.getDramaPoints() < 50) {
            cout << "You made it, although rumors follow your success." << endl;
        }
        else {
            cout << "You enter Mukhouse, but the Shady Agency owns part"
                 << " of your success." << endl;
        }
    }
    else if (player.getDramaPoints() >= 100) {
        cout << "CANCELLED!" << endl;
        cout << "Your drama ended your career before Mukhouse." << endl;
    }
    else {
        cout << "TIME IS UP" << endl;
        cout << "You did not reach 500,000 followers in 28 days." << endl;
    }

    cout << "Final Followers: " << player.getFollowers() << endl;
    cout << "Final Money: $" << player.getMoney() << endl;
    cout << "Final Drama: " << player.getDramaPoints() << endl;
    cout << "Legitimate Wins: " << player.getLegitimateWins() << endl;
    cout << "Rivals Botted: " << player.getRivalsBotted() << endl;
}

int Game::getCurrentDay() {
    return currentDay;
}

bool Game::getGameOver() {
    return gameOver;
}