#include "Room.h"           // Includes the Room class and related definitions

// Constructor: Initializes the room with a name and an empty description
Room::Room(const string& name) : name(name), description() {}

// Sets the description of the room
void Room::setDescription(const string& desc) {
    description = desc;
}

// Adds an item to the room's inventory
void Room::addItem(const string& item) {
    items.push_back(item);
}

// Adds a door to the room, connecting it to another room with specified attributes
void Room::addDoor(
    const string &direction,
    const string &roomName,
    const string &status,
    const string &requiredKey) {
    doors.push_back({
        direction,
        status,
        roomName,
        requiredKey});
}

// Adds an encounter to the room
void Room::addEncounter(const string& encounter) {
    encounters.push_back(encounter);
}

// Getters for room attributes
string Room::getName() const { return name; }                               // Gets the room's name
string Room::getDescription() const { return description; }                 // Gets the room's description
vector<Door> Room::getDoors() const { return doors; }                       // Gets the list of doors in the room
vector<string> Room::getItems() const { return items; }                     // Gets the list of items in the room
vector<string> Room::getEncounters() const { return encounters; }           // Gets the list of encounters in the room

// Checks if a door in the specified direction is locked
bool Room::isDoorLocked(const string& direction) const {
    for (const auto& door : doors) {
        if (door.direction == direction && door.status == "Locked") {
            return true;
        }
    }
    return false;
}

// Unlocks a door in the specified direction if the correct key is provided
bool Room::unlockDoor(const string& direction, const string& key) {
    for (auto& door : doors) {
        if (door.direction == direction && door.status == "Locked" && door.requiredKey == key) {
            door.status = "Open";                                                                           // Changes the door status to "Open"
            return true;                                                                                    // Successfully unlocked
        }
    }
    return false;           // Key didn't match or door isn't locked
}