// testSelect.h | A Header File That Handles Selection For Test Purposes.
#ifndef TESTSELECT_H
#define TESTSELECT_H
#include <iostream>
#include <string>
#include "enemy.h"
#include "items.h"
#include "player.h"
using namespace std;

class testSelect {
public:
	void selectTestOption(Player& player, Enemy& enemy, invItems& invitems);
	void chooseTurnCombat(Player& player, Enemy& enemy, invItems& invitems, int currentTurn, int battleChoice, int enemyBChoice);
};
#endif