#include <iostream>
#include "Player.h"

using namespace std;

int main() {
    Player player("Samani");

    cout << "Name: " << player.getName() << endl;
    cout << "Location: " << player.getCurrentLocation() << endl;
    cout << "Followers: " << player.getFollowers() << endl;
    cout << "Money: $" << player.getMoney() << endl;

    player.addFollowers(50000);
    cout << "Followers after adding: "
         << player.getFollowers() << endl;

    player.addDrama(10);
    cout << "Drama Points: "
         << player.getDramaPoints() << endl;

    player.useAction();
    cout << "Actions Remaining: "
         << player.getActionsRemaining() << endl;

    player.upgradeCamera();
    cout << "Camera Level: "
         << player.getCameraLevel() << endl;

    Item microphone(
        "Professional Microphone",
        "Equipment",
        2,
        500
    );

    player.addItem(microphone);

    cout << endl;
    player.displayInventory();

    cout << endl;
    cout << "Inventory Size: "
         << player.getInventorySize() << endl;

    return 0;
}