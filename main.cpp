// pretty much everything that lets the main file not have to be 1 bajillion lines
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
#include "player.h"
#include "enemy.h"
#include "battle.h"
//#include "difficulty.h"
#include "items.h"
#include "menus.h"
#include <map>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "Room.h"
#include "Map.h"
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// pretty much everything that lets the main file not have to be 1 bajillion lines

using namespace std;

void displayMenu() {
    cout << "1. Go North \n";
    cout << "2. Go South \n";
    cout << "3. Go East \n";
    cout << "4. Go West \n";
    cout << "5. Pickup Item \n";
    cout << "6. Save Game\n";
    cout << "0. Exit Game \n";
}

// Displays the description of the current room, its items, and available exits
void displayCurrentRoom(const Room& room) {

    // Displays room description
    cout << " \n" << room.getDescription() << "\n";
    cout << endl;

    // Lists items present in the room
    cout << "Items: \n";
    for (const auto& item : room.getItems()) {
        cout << " - " << item << "\n";
    }
    cout << endl;

    // Lists exits and their statuses
    cout << "Exits: \n";
    for (const auto& door : room.getDoors()) {
        cout << " - " << door.direction << " (" << door.status << ") \n";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    Menu menus;                    // Creates an instance of Menus.
    Player player;                  // Creates an instance of Player
    enemyList enemylist;            // Creates an instance of enemyList
    //Difficulty difficulty;          // Creates an instance of Difficulty
    Enemy enemy;                    // Creates an instance of Enemy
    BattleLoop battle;              // Creates an instance of testSelect
    Map map;
    Item inventory[9];                    // Creates an instance of invItems
    int itemCount = 0;

    Map gameMap;                        // Initializes the game map
    gameMap.initializeRooms();          // Sets up rooms and their connections


    int choice;             // Stores the player's menu choice
    menus.titleScreen(player);			// The game's title screen.
    while (true) {
        Room& currentRoom = gameMap.getCurrentRoom();           // Gets the player's current room
        displayCurrentRoom(currentRoom);                        // Displays the current room details
        displayMenu();                                          // Displays the available actions
        cin >> choice;                                          // Takes user input for menu selection
        switch (choice) {

            // Move player north
        case 1:
            gameMap.movePlayer("north", player, enemy, inventory, itemCount, enemylist, battle);
            break;

            // Move player south
        case 2:
            gameMap.movePlayer("south", player, enemy, inventory, itemCount, enemylist, battle);
            break;

            // Move player east
        case 3:
            gameMap.movePlayer("east", player, enemy, inventory, itemCount, enemylist, battle);
            break;

            // Move player west
        case 4:
            gameMap.movePlayer("west", player, enemy, inventory, itemCount, enemylist, battle);
            break;

            // Pick up an item in the room
        case 5:
            if (!currentRoom.getItems().empty()) {
                string item = currentRoom.getItems().front();           // Get the first item
                gameMap.addItemToPlayer(item);                          // Add item to player's inventory
                cout << "You picked up: " << item << "\n";              // Notify the player
            }
            else {
                cout << "No items to pick up! \n";                      // Notify if no items are available
            }
            break;
        case 6:
            player.saveGame();
            break;

            // Exit the game
        case 0:
            cout << "Exiting game. Goodbye! \n";
            return 0;

            // Handle invalid menu choices
        default:
            cout << "Please select a valid option. \n";
        }
    }
};