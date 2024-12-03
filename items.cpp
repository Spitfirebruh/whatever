#include <iostream>
#include <vector>
#include <map>
#include "Room.h"
#include "player.h" // Player Header File | Used to reference player health and damage.
#include "items.h" // NPC Header File | Used to define each Non Playable Character.
using namespace std; // Removes the need for "std::".

map<int, Item> itemDatabase = {
	{1, {1, "Small Health Potion", ItemType::HEALING, "Restores 5 HP", 5}},
	{2, {2, "Medium Health Potion", ItemType::HEALING, "Restores 10 HP", 10}},
	{3, {3, "Large Health Potion", ItemType::HEALING, "Restores 20 HP", 20}},
	{4, {4, "Dungeon Key", ItemType::KEY, "Used to open a locked door.", 0}}
};

Item getItemByID(int id) {
	if (itemDatabase.find(id) != itemDatabase.end()) {
		return itemDatabase[id]; // Return the item if found
	}
	else {
		cout << "Item with ID " << id << " does not exist!" << endl;
		return {}; // Return a default/empty Item object if not found
	}
};

void addItem(Item inventory[], int& itemCount, const Item& item) {
	if (itemCount < 9) { // Assuming a fixed size of 9 for simplicity 
		inventory[itemCount++] = item; 
		cout << item.name << " added to inventory." << endl; 
	} 
	else { 
		cout << "Inventory is full." << endl; 
	}
};

void displayInventory(const Item inventory[], int itemCount) {
	cout << "Inventory:" << endl;
	for (int i = 0; i < itemCount; ++i) {
		cout << "ID: " << inventory[i].id
			<< ", Name: " << inventory[i].name
			<< ", Type: ";
		switch (inventory[i].type) {
		case ItemType::HEALING:
			cout << "Healing";
			break;
		case ItemType::WEAPON:
			cout << "Weapon";
			break;
		case ItemType::KEY:
			cout << "Key";
			break;
		case ItemType::BUFF:
			cout << "Buff";
			break;
		case ItemType::DEBUFF:
			cout << "Debuff";
			break;
		}
		cout << ", Description: " << inventory[i].description
			<< ", Effect Value: " << inventory[i].effectValue
			<< endl;
	}
	if (itemCount == 0) {
		cout << "Nothing to be found here (your inventory is empty)." << endl;
	}
};


void Item::applyEffect(Player& player, Enemy& enemy, enemyList& enemylist) {
	switch (type) {
	case ItemType::HEALING:
		player.healthAlteration(enemy, enemylist, effectValue);
		break;
	case ItemType::BUFF:
		player.applyItemAlteration(effectValue);
		break;
	case ItemType::DEBUFF:
		enemy.enemHealthDecrease(player, enemylist, -effectValue);
		break;
	case ItemType::KEY:
		cout << "" << endl;
		break;
	default:
		cout << "Item effect does not exist." << endl;
		break;
	}
};

void pickUpItem(Item inventory[], int& itemCount, const Room& room) {
	auto roomItems = room.getItems();
	for (const auto& itemID : roomItems) {
		Item item = getItemByID(1); // Implement this function to map names to Item objects
		addItem(inventory, itemCount, item);
	}
};