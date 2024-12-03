// player.h | A Header File That Handles Player Attributes
#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <string>
#include "player.h"
#include "enemy.h"
#include "NPCs.h"
#include <vector>
#include <map>
using namespace std;

class Player;
class Enemy;
class enemyList;

enum class ItemType {
	HEALING,
	WEAPON,
	KEY,
	BUFF,
	DEBUFF
};

struct Item {
	int id;
	string name;
	ItemType type;
	string description;
	int effectValue;

	void applyEffect(Player& player, Enemy& enemy, enemyList& enemylist);
};

extern map<int, Item> itemDatabase;

Item getItemByID(int id);

void addItem(Item inventory[], int& itemCount, const Item& item);
void displayInventory(const Item inventory[], int itemCount);

#endif