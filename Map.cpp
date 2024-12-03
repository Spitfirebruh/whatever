#include "Map.h"                // Includes the Map class and related definitions
#include <iostream>             // Provides input/output functionality

// Constructor for the Map class (Sets the starting room)
Map::Map() : currentRoom("Vault Entrance") {}

// Creates a room with the given parameters and adds it to the map
void Map::createRoom(
    const string &name,                         // Room name
    const string &description,                  // Room description
    const vector<string> &items,                // Add items
    const vector<Door> &doors,                  // Add doors
    const vector<string> &encounters) {         // Add encounters
    Room room(name);                            // Initialize the room with its name
    room.setDescription(description);           // Set the room's description

    // Add items to the room
    for (const auto& item : items) {
        room.addItem(item);
    }

    // Add doors to the room
    for (const auto& door : doors) {
        room.addDoor(door.direction, door.connectedRoom, door.status, door.requiredKey);
    }

    // Add encounters to the room
    for (const auto& encounter : encounters) {
        room.addEncounter(encounter);
    }

    addRoom(room);          // Add the fully constructed room to the map
}

// Adds a room to the list of rooms in the map
void Map::addRoom(const Room& room) {
    rooms.push_back(room);
}

// Moves the player in the specified direction if possible
bool Map::movePlayer(const string& direction, Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist, BattleLoop& battle) {
    Room& current = getCurrentRoom(); // Reference to the current room
    for (const auto& door : current.getDoors()) {
        if (door.direction == direction) { // Check if the direction matches a door
            if (door.status == "Open") { // If the door is open, move to the connected room
                previousRoom = currentRoom;  // Save the current room as previous
                currentRoom = door.connectedRoom;
                if (currentRoom == "Prison Chamber") {
                    handleBossEncounter(player, enemy, inventory, itemCount, enemylist, battle);
                }
                else {
                    battle.diceRoll(player, enemy, inventory, itemCount, enemylist);
                }
                return true;
            } else if (door.status == "Locked" && playerHasItem(door.requiredKey)) {
                // If the door is locked, check for the required key and unlock it
                previousRoom = currentRoom;  // Save the current room as previous
                current.unlockDoor(direction, door.requiredKey);
                currentRoom = door.connectedRoom;
                cout << "You used the " << door.requiredKey << " to unlock the door.\n";
                return true;
            } else {
                // If the door is locked and the key is missing
                cout << "The door is locked and requires the " << door.requiredKey << ".\n";
                return false;
            }
        }
    }

    // If no valid door is found in the specified direction
    cout << "This path is not available.\n";
    return false;
}

// Retrieves the current room the player is in
Room& Map::getCurrentRoom() {
    for (auto& room : rooms) {
        if (room.getName() == currentRoom) {
            return room;
        }
    }

    // Return an empty room if the current room cannot be found
    static Room emptyRoom("Empty Room");
    emptyRoom.setDescription("This is an empty room. Nothing to see here!");
    return emptyRoom;
}

// Adds an item to the player's inventory
void Map::addItemToPlayer(const string& item) {
    playerItems.push_back(item);
}

// Checks if the player has a specific item in their inventory
bool Map::playerHasItem(const string& item) const {
    for (const auto& playerItem : playerItems) {
        if (playerItem == item) {
            return true;            // Item found
        }
    }
    return false;                   // Item not found
}

// Initializes the map with predefined rooms, doors, and descriptions
void Map::initializeRooms() {

    // Vault Entrance
    createRoom("Vault Entrance",
               "You are in the vault entrance.",
               {},
               {{ "north", "Open", "Junction 1", "" }},
               {});

    // Junction 1
    createRoom("Junction 1",
               "You are in a junction.",
               {},
               {
                   {"north", "Open", "Empty Corridor", ""},
                   {"south", "Open", "Vault Entrance", ""},
                   {"west", "Locked", "Exit", "ExitKey"},
               },
               {});

    // Empty Corridor
    createRoom("Empty Corridor",
               "You are in an empty corridor.",
               {},
               {
                   {"north", "Open", "Junction 2", ""},
                   {"south", "Open", "Junction 1", ""},
               },
               {});

    // Junction 2
    createRoom("Junction 2",
               "You are in a second junction.",
               {},
               {
                   {"north", "Open", "Security Office", ""},
                   {"south", "Open", "Empty Corridor", ""},
                   {"east", "Open", "Dusty Closet", ""},
                   {"west", "Open", "Long Passage", ""},
               },
               {});

    // Security Office
    createRoom("Security Office",
               "You are in the vault's main security office.",
               {},
               {
                   {"south", "Open", "Junction 2", ""},
               },
               {});

    // Dusty Closet
    createRoom("Dusty Closet",
               "You are in a dusty closet.",
               {},
               {
                   {"south", "Open", "Hidden Junction", ""},
                   {"west", "Open", "Junction 2", ""},
               },
               {});

    // Hidden Junction
    createRoom("Hidden Junction",
               "You are in a hidden passage. There is a mysterious grating in the wall.",
               {},
               {
                   {"north", "Open", "Dusty Closet", ""},
                   {"south", "Open", "Hidden Office", ""},
                   {"east", "Locked", "Secret Stash", "SecretKey"},
               },
               {});

    // Hidden Office
    createRoom("Hidden Office",
               "You are in a hidden office that overlooks the vault entrance.",
               {},
               {
                   {"north", "Open", "Hidden Junction", ""},
                   {"west", "Open", "Junction 1", ""},
               },
               {});

    // Secret Stash
    createRoom("Secret Stash",
               "You have found a secret stash room, dug from the rock long ago.",
               {},
               {
                   {"west", "Open", "Hidden Junction", ""},
               },
               {});

    // Long Passage
    createRoom("Long Passage",
               "You are in a long passage.",
               {},
               {
                   {"east", "Open", "Junction 2", ""},
                   {"west", "Open", "Junction 3", ""},
               },
               {});

    // Junction 3
    createRoom("Junction 3",
               "You are in a third junction.",
               {},
               {
                   {"north", "Locked", "Armory", "ArmoryKey"},
                   {"south", "Open", "Prison Chamber", ""},
                   {"east", "Open", "Long Passage", ""},
               },
               {});

    // Armory
    createRoom("Armory",
               "You are in a poorly stocked armory.",
               {},
               {
                   {"south", "Open", "Junction 3", ""},
               },
               {});

    // Prison Chamber
    createRoom("Prison Chamber",
               "You are in the main prison chamber. Try not to die!",
               {},
               {
                   {"north", "Open", "Junction 3", ""},
                   {"south", "Open", "Exit", ""},
               },
               {});

    // Exit
    createRoom("Exit",
               "You have reached the exit. Thanks for playing!",
               {},
               {},
               {});
}


void Map::handleBossEncounter(Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist, BattleLoop& battle) {
    Room& current = getCurrentRoom();
    if (current.getName() == "Prison Chamber") {
        cout << "You encounter the boss: The Hollowed!" << endl;
        enemylist.bossType(enemy, player, 1);
        battle.chooseTurnCombat(player, enemy, inventory, itemCount, enemylist, 1, 0, 0, 0);

        if (battle.bossWinLoss == false) {
            cout << "You were defeated by The Hollowed. Retreating to the previous room!" << endl;
            moveToPreviousRoom(); // Move the player backward
        }
        else if (battle.bossWinLoss == true) {
            cout << "Congratulations! You defeated The Hollowed and can now proceed south to the exit." << endl;
        }
    }
}

void Map::moveToPreviousRoom() {
    if (!previousRoom.empty()) {
        currentRoom = previousRoom;
        cout << "You have been sent back to " << currentRoom << "." << endl;
    }
    else {
        cout << "There is no previous room to move to!" << endl;
    }
}