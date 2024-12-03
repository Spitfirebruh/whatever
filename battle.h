// testSelect.h | A Header File That Handles Selection For Test Purposes.
#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <string>
#include "enemy.h"
#include "items.h"
#include "player.h"
//#include "difficulty.h"
using namespace std;

class BattleLoop {
public:
	void chooseTurnCombat(Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist, int currentTurn, int battleChoice, int enemyBChoice, int turnCounter);
	void diceRoll(Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist);
	bool bossWinLoss = false;
};
#endif