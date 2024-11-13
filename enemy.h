// player.h | A Header File That Handles Player Attributes
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "NPCs.h"
#include "player.h"
using namespace std;

class Player;
class enemyList;

class Enemy {
	public:
		string enemyName;
		void enemyAttack(enemyList& enemylist, Player& player);
		void enemyBlock(enemyList& enemylist);
		void enemyItemUse(enemyList& enemylist);
		int getEnemyHealth();
		int enemyDamage;
		int enemyHealth;
		int xpReward;
		void enemHealthDecrease(Player& player, int playerDamageAmount);
		void setName(const string& name);
		string getName() const;

};
#endif