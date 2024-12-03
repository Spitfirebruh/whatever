#ifndef MAP_H
#define MAP_H

#include <string>           // Provides the string class
#include <vector>           // Provides the vector container
#include "Room.h"           // Includes the Room and Door class definitions
#include "enemy.h"
#include "NPCs.h"
#include "battle.h"
#include "items.h"

using namespace std;

class Player;
class Enemy;
class enemyList;

// Class: Manages the game map, including rooms, player location, and inventory
class Map {
private:
    vector<Room> rooms;                     // Stores all the rooms in the map
    string currentRoom;                     // Name of the current room the player is in
    string previousRoom;                    // Name of the previous room the player was in
    vector<string> playerItems;             // Tracks the items the player has collected

    // Helper function to create rooms with specified attributes
    void createRoom(const string& name,
                    const string& description,
                    const vector<string>& items = {},                   // Optional list of items in the room
                    const vector<Door>& doors = {},                     // Optional list of doors in the room
                    const vector<string>& encounters = {});             // Optional list of encounters in the room

public:
    Map();          // Constructor: Initialize the map and set the default current room

    // Map management functions
    void addRoom(const Room& room);                     // Adds a room to the map
    bool movePlayer(const string& direction, Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist, BattleLoop& battle);           // Moves the player to a connected room if possible
    Room& getCurrentRoom();                             // Retrieves the current room the player is in
    void moveToPreviousRoom();
    // Map room initialization function
    void initializeRooms();

    // Player inventory functions
    void addItemToPlayer(const string& item);               // Adds an item to the player's inventory
    bool playerHasItem(const string& item) const;           // Checks if the player has a specific item

    // Dev
    void handleBossEncounter(Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist, BattleLoop& battle);
};

#endif // MAP_H