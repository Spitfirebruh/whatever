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
		void enemyAttack(enemyList& enemylist, Player& player);
		void enemyBlock(enemyList& enemylist, int checkTurn);
		bool EnemyIsBlocking = false;
		void enemyHeal(enemyList& enemylist);
		int enemyDamage = 0;
		int enemyHealth = 0;
		int enemHealAmount = 0;
		int xpReward = 0;
		int maxEnemyHealth;
		int scoreReward = 0;
		void enemHealthDecrease(Player& player, enemyList& enemylist, int playerDamageAmount);
		void setName(const string& name);
		string enemyAlteration;
		string enemyName;
		string getName() const;
		string loseDialogue;
		string winDialogue;
		void enemyHealthBar();
		bool isEnemyBoss = false;
		bool disableNotification = false;
	private:
		
};
#endif