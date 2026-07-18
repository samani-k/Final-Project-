#include "Game.h"
#include <fstream>
#include <iostream>
using namespace std;

Game::Game() {
    restaurantCount = 4;
    currentDay = 1;
    gameOver = false;
    playerQuit = false;
    firstFeeExplained = false;

    for (int i = 0; i < 4; i++) {
        competitionCompleted[i] = false;
        restaurantUnlockAnnounced[i] = (i == 0);
        for (int j = 0; j < 4; j++) foodUnlockAnnounced[i][j] = false;
    }

    setupRestaurants();
    loadRivals();
}

void Game::setupRestaurants() {
    restaurants[0] = Restaurant("Raising Cane's", true, 5);
    restaurants[0].setFood(0, Food("Three Finger Combo", 35, 0, 900));
    restaurants[0].setFood(1, Food("Box Combo", 55, 8000, 1300));
    restaurants[0].setFood(2, Food("Caniac Combo", 80, 20000, 1800));
    restaurants[0].setFood(3, Food("Tailgate Feast", 120, 35000, 2400));

    restaurants[1] = Restaurant("In-N-Out", false, 10);
    restaurants[1].setFood(0, Food("Cheeseburger", 50, 45000, 1700));
    restaurants[1].setFood(1, Food("Animal Style Fries", 75, 60000, 2200));
    restaurants[1].setFood(2, Food("Double-Double", 110, 80000, 2900));
    restaurants[1].setFood(3, Food("Four-by-Four", 150, 105000, 3700));

    restaurants[2] = Restaurant("El Pollo Loco", false, 15);
    restaurants[2].setFood(0, Food("BRC Burrito Meal", 75, 130000, 2800));
    restaurants[2].setFood(1, Food("Chicken Tostada", 110, 155000, 3500));
    restaurants[2].setFood(2, Food("Three-Piece Meal", 150, 185000, 4300));
    restaurants[2].setFood(3, Food("Family Chicken Feast", 200, 220000, 5200));

    restaurants[3] = Restaurant("Hot Pot", false, 20);
    restaurants[3].setFood(0, Food("Vegetable Hot Pot", 120, 260000, 4500));
    restaurants[3].setFood(1, Food("Beef Hot Pot", 175, 300000, 5500));
    restaurants[3].setFood(2, Food("Seafood Hot Pot", 225, 340000, 6700));
    restaurants[3].setFood(3, Food("Ultimate Hot Pot Feast", 300, 390000, 8200));
}

void Game::loadRivals() {
    ifstream inputFile("Rivals.txt");

    if (!inputFile.is_open()) {
        restaurants[0].setRival(Rival("CrunchiestSon", "Raising Cane's", "Featured Creator", "My crunch is undefeatable.", 28));
        restaurants[1].setRival(Rival("TungTungEathur", "In-N-Out", "Featured Creator", "You will never beat me.", 42));
        restaurants[2].setRival(Rival("FolkValleyMukbangs", "El Pollo Loco", "Featured Creator", "You do not compare to me.", 58));
        restaurants[3].setRival(Rival("Unc_eats", "Hot Pot", "Featured Creator", "Pack it up. You are cooked.", 75));
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

        restaurants[i].setRival(Rival(name, location, role, dialogue, skill));
    }
}

void Game::displayIntroduction() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "             MUKBANG CITY" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "You have always wanted to become a content creator," << endl;
    cout << "but you never knew how to turn it into a real career." << endl;
    cout << endl;
    cout << "Then your phone rings." << endl;
    cout << endl;
    cout << "Mia, your old friend, is now a creator manager in" << endl;
    cout << "Mukbang City. She has one ambitious idea:" << endl;
    cout << endl;
    cout << "Turn you into the city's next mukbang star." << endl;
    cout << endl;
    cout << "Mukhouse applications close in 28 days. Only creators" << endl;
    cout << "with at least 500,000 followers will be considered." << endl;
    cout << endl;
    cout << "Mia:" << endl;
    cout << "\"I can help you build a career, but you have to commit." << endl;
    cout << "Restaurants, videos, competitions--the whole thing.\"" << endl;
    cout << endl;
    cout << "Accept Mia's offer? (y/n): ";
}

void Game::startGame() {
    displayIntroduction();

    char accept;
    cin >> accept;
    if (accept != 'y' && accept != 'Y') {
        cout << endl << "You decide not to enter Mukbang City." << endl;
        return;
    }

    string username;
    cout << endl << "Enter your creator username: ";
    cin >> username;
    if (username.length() > 0 && username[0] == '@') username = username.substr(1);
    player = Player(username);

    cout << endl;
    cout << "Welcome, @" << player.getName() << "!" << endl;
    cout << endl;
    cout << "Mia lends you $3000 and gives you a Basic Camera." << endl;
    cout << endl;
    cout << "You have:" << endl;
    cout << "- 28 days" << endl;
    cout << "- 3 actions per day" << endl;
    cout << "- 0 followers" << endl;
    cout << "- $3000" << endl;
    cout << "- 1 Basic Camera" << endl;
    cout << endl;
    cout << "Actions are used when you:" << endl;
    cout << "- successfully create content" << endl;
    cout << "- buy an equipment upgrade" << endl;
    cout << "- enter a featured creator competition" << endl;
    cout << "- use a Shady Agency shortcut" << endl;
    cout << endl;
    cout << "Traveling, viewing information, and locked choices are free." << endl;
    cout << endl;
    cout << "Reach 500,000 followers before the end of Day 28." << endl;
    cout << "Day 1 begins at your apartment." << endl;

    while (!gameOver) {
        displayMainMenu();
        int choice;
        cin >> choice;
        handleMainMenuChoice(choice);

        if (player.getDramaPoints() >= 100) gameOver = true;
        if (player.getMoney() < 0) gameOver = true;
    }

    displayEnding();
}

void Game::displayMap() {
    string apartment = player.getCurrentLocation() == "Apartment" ? "[*Apartment]" : "[Apartment]";
    string equipment = player.getCurrentLocation() == "Equipment Store" ? "[*Equipment Store]" : "[Equipment Store]";
    string agency = player.getCurrentLocation() == "Shady Creator Agency" ? "[*Shady Creator Agency]" : "[Shady Creator Agency]";

    string names[4];
    for (int i = 0; i < 4; i++) {
        if (player.getFollowers() < getRestaurantUnlockRequirement(i)) names[i] = "[LOCKED]";
        else if (player.getCurrentLocation() == restaurants[i].getName()) names[i] = "[*" + restaurants[i].getName() + "]";
        else names[i] = "[" + restaurants[i].getName() + "]";
    }

    cout << endl;
    cout << "MAP" << endl;
    cout << "                         " << equipment << endl;
    cout << "                                |" << endl;
    cout << apartment << " -- " << names[0] << " -- " << names[1] << endl;
    cout << "                                |" << endl;
    cout << "                     " << agency << endl;
    cout << endl;
    cout << "                     " << names[2] << endl;
    cout << "                          |" << endl;
    cout << "                     " << names[3] << endl;
    cout << "* = current location" << endl;
}

void Game::displayMainMenu() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "DAY " << currentDay << " / 28" << endl;
    cout << "----------------------------------------" << endl;
    cout << "@" << player.getName() << endl;
    cout << "Followers: " << player.getFollowers() << " / 500000" << endl;
    cout << "Money: $" << player.getMoney() << endl;
    cout << "Actions: " << player.getActionsRemaining() << " / 3" << endl;
    cout << "Location: " << player.getCurrentLocation() << endl;
    cout << endl;
    cout << "Next Unlock: " << getNextUnlockText() << endl;
    displayMap();
    cout << endl;
    cout << "1. Travel" << endl;
    cout << "2. Create Content" << endl;
    cout << "3. Enter Location" << endl;
    cout << "4. View Profile" << endl;
    cout << "5. End Day" << endl;
    cout << "6. Quit" << endl;
    cout << endl << "Choice: ";
}

void Game::handleMainMenuChoice(int choice) {
    if (choice == 1) travel();
    else if (choice == 2) createContent();
    else if (choice == 3) enterLocation();
    else if (choice == 4) viewProfile();
    else if (choice == 5) endDay();
    else if (choice == 6) {
        char confirm;
        cout << "Quit the game? (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            playerQuit = true;
            gameOver = true;
        }
    }
    else cout << "Invalid choice." << endl;
}

int Game::getRestaurantUnlockRequirement(int index) {
    int requirements[4] = {0, 45000, 130000, 260000};
    return requirements[index];
}

int Game::getCurrentRestaurantIndex() {
    for (int i = 0; i < 4; i++) {
        if (player.getCurrentLocation() == restaurants[i].getName()) return i;
    }
    return -1;
}

void Game::travel() {
    cout << endl;
    cout << "TRAVEL" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Apartment" << endl;
    cout << "2. Raising Cane's" << endl;
    for (int i = 1; i < 4; i++) {
        cout << i + 2 << ". ";
        if (player.getFollowers() >= getRestaurantUnlockRequirement(i)) cout << restaurants[i].getName();
        else cout << "LOCKED";
        cout << endl;
    }
    cout << "6. Equipment Store" << endl;
    cout << "7. Shady Creator Agency" << endl;
    cout << "8. Cancel" << endl;
    cout << endl << "Choice: ";

    int choice;
    cin >> choice;
    string destination = "";

    if (choice == 1) destination = "Apartment";
    else if (choice >= 2 && choice <= 5) {
        int index = choice - 2;
        if (player.getFollowers() < getRestaurantUnlockRequirement(index)) {
            cout << "That location is still locked." << endl;
            return;
        }
        destination = restaurants[index].getName();
        restaurants[index].setUnlocked(true);
    }
    else if (choice == 6) destination = "Equipment Store";
    else if (choice == 7) destination = "Shady Creator Agency";
    else if (choice == 8) return;
    else {
        cout << "Invalid choice." << endl;
        return;
    }

    player.setCurrentLocation(destination);
    cout << endl << "You traveled to " << destination << "." << endl;
}

int Game::getEquipmentBonus() {
    return (player.getCameraLevel() - 1) * 250
        + player.getLightingLevel() * 300
        + player.getMicrophoneLevel() * 250;
}

int Game::getContentFollowers(Food food, int contentChoice) {
    int variation = (currentDay * 137 + player.getActionsRemaining() * 83 + player.getFollowers()) % 501;
    int followers = food.getContentBonus() + getEquipmentBonus();

    if (contentChoice == 1) followers += 300 + variation / 3;
    else if (contentChoice == 2) followers += 150 + variation / 2;
    else followers += variation - 150;

    if (followers < 300) followers = 300;
    return followers;
}

int Game::getContentMoney(int contentChoice) {
    if (contentChoice == 1) return 90;
    if (contentChoice == 2) return 170;
    return 40;
}

int Game::getLiveDonations() {
    int base = player.getFollowers() / 250;
    int variation = (currentDay * 29 + player.getActionsRemaining() * 47 + player.getFollowers()) % 121;
    return base + variation;
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
    cout << endl << "Choose a food: ";
    int foodChoice;
    cin >> foodChoice;
    if (foodChoice == 5) return;
    if (foodChoice < 1 || foodChoice > 4) {
        cout << "Invalid choice." << endl;
        return;
    }

    Food food = restaurants[index].getFood(foodChoice - 1);
    if (!food.isUnlocked(player.getFollowers())) {
        cout << endl << food.getName() << " is still locked." << endl;
        cout << "Reach " << food.getFollowerRequirement() << " followers to unlock it." << endl;
        cout << "No money was spent and no action was used." << endl;
        return;
    }

    cout << endl;
    cout << "CHOOSE CONTENT TYPE" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. TikTok Mukbang" << endl;
    cout << "   Quick and reliable follower growth." << endl;
    cout << endl;
    cout << "2. YouTube Mukbang" << endl;
    cout << "   Steady growth with better ad money." << endl;
    cout << endl;
    cout << "3. Live Stream" << endl;
    cout << "   Unpredictable growth with viewer donations." << endl;
    cout << endl;
    cout << "4. Cancel" << endl;
    cout << endl << "Choice: ";

    int contentChoice;
    cin >> contentChoice;
    if (contentChoice == 4) return;
    if (contentChoice < 1 || contentChoice > 3) {
        cout << "Invalid choice." << endl;
        return;
    }

    if (!player.spendMoney(food.getPrice())) {
        cout << "You cannot afford that food." << endl;
        return;
    }

    int followersEarned = getContentFollowers(food, contentChoice);
    int moneyEarned = getContentMoney(contentChoice);
    int donations = 0;
    string contentName;

    if (contentChoice == 1) contentName = "TikTok Mukbang";
    else if (contentChoice == 2) contentName = "YouTube Mukbang";
    else {
        contentName = "Live Stream";
        donations = getLiveDonations();
    }

    player.addFollowers(followersEarned);
    player.addMoney(moneyEarned + donations);
    player.useAction();

    cout << endl;
    cout << "You filmed a " << contentName << " featuring" << endl;
    cout << "the " << food.getName() << " at " << restaurants[index].getName() << "." << endl;
    cout << endl;
    cout << "Followers gained: " << followersEarned << endl;
    cout << "Money earned: $" << moneyEarned << endl;
    if (contentChoice == 3) cout << "Donations received: $" << donations << endl;
    cout << "Food cost: $" << food.getPrice() << endl;
    cout << "Actions remaining: " << player.getActionsRemaining() << endl;

    announceUnlocks();
}

void Game::enterLocation() {
    if (player.getCurrentLocation() == "Apartment") apartmentMenu();
    else if (player.getCurrentLocation() == "Equipment Store") equipmentStore();
    else if (player.getCurrentLocation() == "Shady Creator Agency") shadyAgency();
    else {
        cout << endl << "You enter " << player.getCurrentLocation() << "." << endl;
        cout << "Choose Create Content from the main menu when you are ready to film." << endl;
    }
}

void Game::apartmentMenu() {
    cout << endl;
    cout << "APARTMENT" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Mia is reviewing your latest account numbers." << endl;
    cout << endl;
    cout << "1. Ask about actions" << endl;
    cout << "2. Ask about competitions" << endl;
    cout << "3. Ask about the goal" << endl;
    cout << "4. Leave" << endl;
    cout << endl << "Choice: ";

    int choice;
    cin >> choice;
    cout << endl;
    if (choice == 1) {
        cout << "Mia:" << endl;
        cout << "\"Creating content, buying an upgrade, entering a" << endl;
        cout << "competition, and using a shady shortcut cost one action." << endl;
        cout << "Traveling and checking information are free.\"" << endl;
    }
    else if (choice == 2) {
        cout << "Mia:" << endl;
        cout << "\"Competitions happen on Days 5, 10, 15, and 20." << endl;
        cout << "They cost one action and only happen on that day." << endl;
        cout << "Day 20 is the final competition and requires 300,000 followers." << endl;
        cout << "Winning badges helps in later competitions.\"" << endl;
    }
    else if (choice == 3) {
        cout << "Mia:" << endl;
        cout << "\"Reach 500,000 followers before the end of Day 28." << endl;
        cout << "Food, equipment, competitions, and smart decisions help you grow.\"" << endl;
    }
}

void Game::equipmentStore() {
    cout << endl;
    cout << "EQUIPMENT STORE" << endl;
    cout << "----------------------------------------" << endl;
    cout << "A clerk stands behind a wall of cameras, lights, and microphones." << endl;
    cout << endl;
    cout << "1. Upgrade Camera - $1200" << endl;
    cout << "2. Buy or Upgrade Lighting - $1000" << endl;
    cout << "3. Buy or Upgrade Microphone - $1000" << endl;
    cout << "4. Ask About My Equipment" << endl;
    cout << "5. Leave" << endl;
    cout << endl;
    cout << "Buying an upgrade costs 1 action." << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;
    if (choice == 5) return;

    if (choice == 4) {
        cout << endl << "Clerk:" << endl;
        cout << "\"Your camera gives every post a small boost." << endl;
        if (player.getLightingLevel() == 0) cout << "You do not own proper lighting yet." << endl;
        else cout << "Your lighting helps your videos look more polished." << endl;
        if (player.getMicrophoneLevel() == 0) cout << "You do not own an external microphone yet." << endl;
        else cout << "Your microphone improves the quality of your audio." << endl;
        cout << "Stronger equipment makes your content more consistent.\"" << endl;
        return;
    }

    if (player.getActionsRemaining() == 0) {
        cout << "You have no actions remaining today." << endl;
        return;
    }

    int cost = 0;
    if (choice == 1) cost = 1200;
    else if (choice == 2 || choice == 3) cost = 1000;
    else {
        cout << "Invalid choice." << endl;
        return;
    }

    if (!player.spendMoney(cost)) {
        cout << "You cannot afford that upgrade." << endl;
        return;
    }

    if (choice == 1) player.upgradeCamera();
    else if (choice == 2) player.upgradeLighting();
    else player.upgradeMicrophone();

    player.useAction();
    cout << "Upgrade purchased. Your content will now perform more consistently." << endl;
}

void Game::shadyAgency() {
    cout << endl;
    cout << "SHADY CREATOR AGENCY" << endl;
    cout << "----------------------------------------" << endl;
    cout << "A flickering sign hangs above a tiny office." << endl;
    cout << "An agent wearing sunglasses indoors looks up." << endl;
    cout << endl;
    cout << "Agent:" << endl;
    cout << "\"Welcome. Everything here is probably legal.\"" << endl;
    cout << endl;
    cout << "1. Buy fake followers - $700, +10 Drama" << endl;
    cout << "2. Sabotage a rival - $1500, +20 Drama" << endl;
    cout << "3. Fake a viral trend - $1000, +30 Drama" << endl;
    cout << "4. Ask about the risks" << endl;
    cout << "5. Leave" << endl;
    cout << endl;
    cout << "Using a shortcut costs 1 action." << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    if (choice == 4) {
        cout << endl << "Agent:" << endl;
        cout << "\"Every shortcut adds Drama Points." << endl;
        cout << "At 100 Drama Points, your career ends immediately." << endl;
        cout << "Drama can also lower your competition performance." << endl;
        cout << "The faster option is not always the safer option.\"" << endl;
        return;
    }

    if (choice == 5) {
        string goodbyes[4] = {
            "Remember: screenshots are forever.",
            "If anyone asks, you were never here.",
            "Stay famous. Stay vague.",
            "Please leave before the landlord notices."
        };
        int index = (currentDay + player.getActionsRemaining() + player.getDramaPoints()) % 4;
        cout << endl << "Agent:" << endl;
        cout << "\"" << goodbyes[index] << "\"" << endl;
        return;
    }

    if (player.getActionsRemaining() == 0) {
        cout << "You have no actions remaining today." << endl;
        return;
    }

    if (choice == 1) {
        if (!player.spendMoney(700)) {
            cout << "You cannot afford this shortcut." << endl;
            return;
        }
        player.addFollowers(9000);
        player.addDrama(10);
        player.useAction();
        cout << "9,000 suspicious new followers appear on your account." << endl;
    }
    else if (choice == 2) {
        cout << endl << "Choose a rival:" << endl;
        for (int i = 0; i < 4; i++) {
            Rival r = restaurants[i].getRival();
            cout << i + 1 << ". " << r.getName();
            if (r.getBanned()) cout << " [BANNED]";
            cout << endl;
        }
        int rivalChoice;
        cout << "Choice: ";
        cin >> rivalChoice;
        int index = rivalChoice - 1;
        if (index < 0 || index >= 4) {
            cout << "Invalid rival." << endl;
            return;
        }
        Rival r = restaurants[index].getRival();
        if (r.getBanned()) {
            cout << "That rival is already banned." << endl;
            return;
        }
        if (!player.spendMoney(1500)) {
            cout << "You cannot afford this shortcut." << endl;
            return;
        }
        r.setBanned(true);
        restaurants[index].setRival(r);
        player.addRivalBanned();
        player.addDrama(20);
        player.useAction();
        cout << r.getName() << " has been removed from future competition." << endl;
    }
    else if (choice == 3) {
        if (!player.spendMoney(1000)) {
            cout << "You cannot afford this shortcut." << endl;
            return;
        }
        player.addFollowers(22000);
        player.addDrama(30);
        player.useAction();
        cout << "A fake trend gives you 22,000 followers." << endl;
    }
    else cout << "Invalid choice." << endl;

    announceUnlocks();
}

void Game::viewProfile() {
    cout << endl;
    cout << "PLAYER PROFILE" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Creator: @" << player.getName() << endl;
    cout << "Followers: " << player.getFollowers() << " / 500000" << endl;
    cout << "Money: $" << player.getMoney() << endl;
    cout << "Drama: " << player.getDramaPoints() << " / 100" << endl;
    cout << "Day: " << currentDay << " / 28" << endl;
    cout << endl;
    cout << "Equipment:" << endl;
    cout << "- Camera: Level " << player.getCameraLevel() << endl;
    if (player.getLightingLevel() == 0) cout << "- Lighting: Not owned" << endl;
    else cout << "- Lighting: Level " << player.getLightingLevel() << endl;
    if (player.getMicrophoneLevel() == 0) cout << "- Microphone: Not owned" << endl;
    else cout << "- Microphone: Level " << player.getMicrophoneLevel() << endl;
    cout << endl;
    cout << "Competition wins: " << player.getCompetitionWins() << endl;
    cout << "Rivals banned: " << player.getRivalsBanned() << endl;
    cout << "Badges slightly improve later competition scores." << endl;
    cout << endl;
    player.displayInventory();
    cout << endl;
    cout << "1. Return to menu" << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
}

void Game::announceUnlocks() {
    for (int i = 1; i < 4; i++) {
        if (!restaurantUnlockAnnounced[i]
            && player.getFollowers() >= getRestaurantUnlockRequirement(i)) {
            restaurantUnlockAnnounced[i] = true;
            restaurants[i].setUnlocked(true);
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "NEW LOCATION UNLOCKED!" << endl;
            cout << "----------------------------------------" << endl;
            cout << restaurants[i].getName() << " is now open for travel." << endl;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (player.getFollowers() >= getRestaurantUnlockRequirement(i)) {
            for (int j = 0; j < 4; j++) {
                Food food = restaurants[i].getFood(j);
                if (!foodUnlockAnnounced[i][j]
                    && player.getFollowers() >= food.getFollowerRequirement()) {
                    foodUnlockAnnounced[i][j] = true;
                    if (food.getFollowerRequirement() > 0) {
                        cout << endl;
                        cout << "----------------------------------------" << endl;
                        cout << "NEW FOOD UNLOCKED!" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << food.getName() << " is now available at "
                             << restaurants[i].getName() << "." << endl;
                    }
                }
            }
        }
    }
}

void Game::announceCompetitionDay() {
    for (int i = 0; i < 4; i++) {
        if (currentDay == restaurants[i].getCompetitionDay()) {
            cout << endl;
            cout << "----------------------------------------" << endl;
            if (currentDay == 20) cout << "FINAL COMPETITION DAY!" << endl;
            else cout << "COMPETITION DAY!" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The " << restaurants[i].getName() << " Featured Creator Competition is today." << endl;
            cout << "Entering costs 1 action and the competition disappears tomorrow." << endl;
            if (currentDay == 5) {
                cout << endl;
                cout << "Mia:" << endl;
                cout << "\"Competitions happen on Days 5, 10, 15, and 20." << endl;
                cout << "Winning earns followers, money, and a badge." << endl;
                cout << "The Day 20 final requires 300,000 followers.\"" << endl;
            }
            if (currentDay == 20) cout << "Required followers: 300000" << endl;

            if (currentDay == 20 && player.getFollowers() < 300000) {
                cout << "You do not have enough followers to qualify." << endl;
                competitionCompleted[i] = true;
                return;
            }

            if (player.getActionsRemaining() == 0) {
                cout << "You have no actions available, so you miss the competition." << endl;
                competitionCompleted[i] = true;
                return;
            }

            cout << endl << "Enter competition? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y') runCompetition(i);
            else {
                cout << "You skip today's competition." << endl;
                competitionCompleted[i] = true;
            }
            return;
        }
    }
}

void Game::runCompetition(int index) {
    Rival rival = restaurants[index].getRival();
    player.useAction();
    competitionCompleted[index] = true;

    cout << endl;
    cout << "========================================" << endl;
    cout << "     FEATURED CREATOR COMPETITION" << endl;
    cout << "========================================" << endl;
    cout << "Location: " << restaurants[index].getName() << endl;

    string formats[4] = {
        "Live Stream Mukbang",
        "TikTok Mukbang",
        "YouTube Mukbang",
        "Live Stream Mukbang"
    };
    cout << "Format: " << formats[index] << endl;
    cout << "Opponent: " << rival.getName() << endl;
    cout << endl;

    if (rival.getBanned()) {
        cout << rival.getName() << " was banned before the competition." << endl;
        cout << "You win by default." << endl;
    }
    else {
        cout << "The restaurant fills with viewers as both creators" << endl;
        cout << "prepare their meals and start the broadcast." << endl;
        cout << endl;
        rival.talk();
        cout << endl;
        cout << "Calibrating score based on:" << endl;
        cout << "- follower count" << endl;
        cout << "- equipment quality" << endl;
        cout << "- past competition badges" << endl;
        cout << "- current Drama Points" << endl;
        cout << "- rival difficulty" << endl;
        cout << endl;

        int playerScore = player.getFollowers() / 5000
            + player.getCameraLevel() * 3
            + player.getLightingLevel() * 2
            + player.getMicrophoneLevel() * 2
            + player.getCompetitionWins() * 4
            - player.getDramaPoints() / 10
            + currentDay;

        int rivalScore = rival.getSkillLevel();
        cout << "Your final score: " << playerScore << endl;
        cout << rival.getName() << "'s score: " << rivalScore << endl;

        if (playerScore < rivalScore) {
            cout << endl << "You lost the competition." << endl;
            cout << "You gain 1500 followers for participating." << endl;
            player.addFollowers(1500);
            announceUnlocks();
            return;
        }
    }

    int rewards[4] = {10000, 18000, 28000, 50000};
    int moneyRewards[4] = {500, 750, 1000, 1600};
    player.addFollowers(rewards[index]);
    player.addMoney(moneyRewards[index]);
    player.addCompetitionWin();
    player.addItem(Item(restaurants[index].getName() + " Badge", "Badge", 1));

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "YOU WON!" << endl;
    cout << "----------------------------------------" << endl;
    cout << "+" << rewards[index] << " followers" << endl;
    cout << "+$" << moneyRewards[index] << endl;
    cout << "+" << restaurants[index].getName() << " Featured Creator Badge" << endl;
    cout << "The badge slightly improves future competition scores." << endl;
    announceUnlocks();
}

void Game::processFees() {
    if (currentDay == 7 || currentDay == 14 || currentDay == 21 || currentDay == 28) {
        int rent = 600;
        int managerFee = 250;
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "WEEKLY EXPENSES" << endl;
        cout << "----------------------------------------" << endl;

        if (player.getMoney() >= rent + managerFee) {
            player.spendMoney(rent + managerFee);
            cout << "Apartment rent: -$600" << endl;
            cout << "Mia's manager fee: -$250" << endl;
            cout << "Remaining money: $" << player.getMoney() << endl;
        }
        else {
            cout << "You cannot afford the $850 weekly expenses." << endl;
            player.spendMoney(player.getMoney());
            gameOver = true;
        }

        if (!firstFeeExplained) {
            firstFeeExplained = true;
            cout << endl;
            cout << "Mia:" << endl;
            cout << "\"Rent and my manager fee are charged every 7 days.\"" << endl;
        }
    }
}

void Game::startNewDay() {
    player.resetActions();
    player.setCurrentLocation("Apartment");

    cout << endl;
    cout << "Day " << currentDay << " begins." << endl;
    cout << "You return to your apartment." << endl;
    cout << "Actions restored to 3." << endl;

    processFees();
    if (!gameOver) announceCompetitionDay();
}

void Game::endDay() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "DAY " << currentDay << " COMPLETE" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Followers: " << player.getFollowers() << endl;
    cout << "Money: $" << player.getMoney() << endl;
    cout << "Drama: " << player.getDramaPoints() << endl;

    if (currentDay == 28) {
        gameOver = true;
        return;
    }

    currentDay++;
    startNewDay();
}

string Game::getNextUnlockText() {
    int followers = player.getFollowers();

    for (int i = 0; i < 4; i++) {
        if (followers >= getRestaurantUnlockRequirement(i)) {
            for (int j = 0; j < 4; j++) {
                Food food = restaurants[i].getFood(j);
                if (followers < food.getFollowerRequirement()) {
                    return food.getName() + " at " + to_string(food.getFollowerRequirement()) + " followers";
                }
            }
        }

        if (followers < getRestaurantUnlockRequirement(i)) {
            return "A new restaurant at " + to_string(getRestaurantUnlockRequirement(i)) + " followers";
        }
    }

    return "Reach 500000 followers";
}

void Game::displayEnding() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "                GAME OVER" << endl;
    cout << "========================================" << endl;

    if (playerQuit) {
        cout << "You leave Mukbang City before applications close." << endl;
    }
    else if (player.getDramaPoints() >= 100) {
        cout << "Your Drama Points reach 100 and your creator career collapses." << endl;
    }
    else if (player.getMoney() <= 0) {
        cout << "You run out of money and can no longer continue your career." << endl;
    }
    else if (player.getFollowers() >= 500000) {
        cout << "@" << player.getName() << " qualifies for Mukhouse!" << endl;
        cout << "You finish with " << player.getFollowers() << " followers." << endl;
    }
    else {
        cout << "Applications close before you reach 500000 followers." << endl;
        cout << "Final followers: " << player.getFollowers() << endl;
    }
}