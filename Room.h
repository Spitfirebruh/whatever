#ifndef ROOM_H
#define ROOM_H

#include <string>           // Provides the string class
#include <vector>           // Provides the vector container

using namespace std;

// Represents a door in a room, including its direction, status, connected room, and required key
struct Door {
    string direction;               // Direction of the door ("north", "south", "east", "west")
    string status;                  // Status of the door ("Open" or "Locked")
    string connectedRoom;           // Name of the room the door connects to
    string requiredKey;             // Key required to unlock the door, if any
};

// Represents a room in the game, including its name, description, doors, items, and encounters
class Room {
private:
    string name;                        // Name of the room
    string description;                 // Description of the room
    vector<Door> doors;                 // List of doors in the room
    vector<string> items;               // List of items in the room
    vector<string> encounters;          // List of encounters in the room

public:

    // Constructor: Initializes a room with the given name
    Room(const string& name);

    // Functions to manage doors
    void addDoor(const string& direction, const string& roomName, const string& status, const string& requiredKey = "");

    // Functions to manage items
    void addItem(const string& item);

    // Functions to manage encounters
    void addEncounter(const string& encounter);     // Adds an encounter to the room
    vector<string> getEncounters() const;           // Retrieves all encounters in the room

    // Setter for the room's description
    void setDescription(const string& desc);

    // Getters for room attributes
    string getName() const;                         // Retrieves the room's name
    string getDescription() const;                  // Retrieves the room's description
    vector<Door> getDoors() const;                  // Retrieves the list of doors
    vector<string> getItems() const;                // Retrieves the list of items

    // Functions to check and manage door locks
    bool isDoorLocked(const string& direction) const;                       // Checks if a door is locked
    bool unlockDoor(const string& direction, const string& key);            // Unlocks a door with a key
};

#endif // ROOM_H