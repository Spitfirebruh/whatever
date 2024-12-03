#include "movement.h"
#include "Map.h"
#include "player.h"
#include "enemy.h"
#include "battle.h"
#include "Room.h"
#include <iostream>

using namespace std;

// States and lets the character move
void movement(Map& map, Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist, BattleLoop& battle, const std::string& direction) {

	map.movePlayer(direction, player, enemy, inventory, itemCount, enemylist, battle);
	cout << "Player moved " << direction << "." << endl;
}

// Communicates that an item was picked up
void itemPickup(Room& currentRoom, Map& map) {
	string item;
	if (!currentRoom.getItems().empty()) {
		item = currentRoom.getItems().front();
		map.addItemToPlayer(item);
		cout << "You picked up: " << item << endl;
	}
	else {
		cout << "No item to pick up! \n";
	}
}

// Communicates a successful save game
void saveGame(Player& player) {
	player.saveGame();
	cout << "Game saved successfully." << endl;
}

// Communicates a exit of the game
int exitGame() {
	cout << "Exiting game. Goodbye! \n";
	return 0;
}