#include <iostream>
#include "Map.h"            // Includes the Map class and related definitions

using namespace std;

// Displays the menu of actions the player can perform
void displayMenu() {
    cout << "1. Go North \n";
    cout << "2. Go South \n";
    cout << "3. Go East \n";
    cout << "4. Go West \n";
    cout << "5. Pickup Item \n";
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
    Map gameMap;                        // Initializes the game map
    gameMap.initializeRooms();          // Sets up rooms and their connections

    int choice;             // Stores the player's menu choice

    while (true) {
        Room& currentRoom = gameMap.getCurrentRoom();           // Gets the player's current room
        displayCurrentRoom(currentRoom);                        // Displays the current room details
        displayMenu();                                          // Displays the available actions
        cin >> choice;                                          // Takes user input for menu selection

        switch (choice) {

            // Move player north
            case 1:
                gameMap.movePlayer("north");
                break;

            // Move player south
            case 2:
                gameMap.movePlayer("south");
                break;

            // Move player east
            case 3:
                gameMap.movePlayer("east");
                break;

            // Move player west
            case 4:
                gameMap.movePlayer("west");
                break;

            // Pick up an item in the room
            case 5:
                if (!currentRoom.getItems().empty()) {
                    string item = currentRoom.getItems().front();           // Get the first item
                    gameMap.addItemToPlayer(item);                          // Add item to player's inventory
                    cout << "You picked up: " << item << "\n";              // Notify the player
                } else {
                    cout << "No items to pick up! \n";                      // Notify if no items are available
                }
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
}
