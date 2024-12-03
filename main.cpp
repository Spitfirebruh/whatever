
#include "player.h"     // Includes the player & related definitions
#include "enemy.h"      // Includes the enemy & related definitions
#include "battle.h"     // Includes the battle & related definitions
#include "items.h"      // Includes the items & related definitions
#include "menus.h"      // Includes menus & related definitions
#include <map>          // Includes the map & related definitions
#include "movement.h"   // Includes the movement & related definitions
#include <iostream>     // Gives input/output operations
#include <string>       // Gives strings of characters
#include <cstdlib>      
#include <ctime>        
#include <stdio.h>      
#include "Room.h"       // Includes the Room & related definitions
#include "Map.h"        // Includes the Map & related definitions


using namespace std;
// Displays the menu of actions the player can perform
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
    Menu menus;                     // Creates an instance of Menus.
    Player player;                  // Creates an instance of Player
    enemyList enemylist;            // Creates an instance of enemyList
    Enemy enemy;                    // Creates an instance of Enemy
    BattleLoop battle;              // Creates an instance of battle
    Map map;                        // Creates an instance of map
    Item inventory[9];              // Creates an array of 9 for the inventory
    int itemCount = 0;              // Starter inventory hand nothing

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
            movement(gameMap, player, enemy, inventory, itemCount, enemylist, battle, "north");
            break;

            // Move player south
        case 2:
            movement(gameMap, player, enemy, inventory, itemCount, enemylist, battle, "south");
            break;

            // Move player east
        case 3:
            movement(gameMap, player, enemy, inventory, itemCount, enemylist, battle, "east");
            break;

            // Move player west
        case 4:
            movement(gameMap, player, enemy, inventory, itemCount, enemylist, battle, "west");
            break;

            // Pick up an item in the room
        case 5:
            itemPickup(currentRoom, gameMap);
            break;
        case 6:
            saveGame(player);
            break;

            // Exit the game
        case 0:
            return exitGame();

            // Handle invalid menu choices
        default:
            cout << "Please select a valid option. \n";
        }
    }
};
