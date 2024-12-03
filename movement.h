#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "movement.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"
#include "Room.h"
#include <vector>
#include <string>

// Represents the movements of the character
void movement(Map& map, Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist, BattleLoop& battle, const std::string& direction);

// Allows the charcater to pick up items
void itemPickup(Room& currentRoom, Map& map);

// Allows a save game
void saveGame(Player& player);

// Freedom.
int exitGame();

#endif