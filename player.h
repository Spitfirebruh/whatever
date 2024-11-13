// player.h | A Header File That Handles Player Attributes
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "enemy.h"
#include "items.h"
using namespace std;
   
class Enemy;
class invItems;

class Player {
	public:
		void playerAttack(Enemy &enemy);
		void playerBlock();
		void playerInventory(invItems &invitems);
		int getPlayerHealth();
		int level = 1;
		int exp = 0;
		int maximumHealth = 100;
		void healthAlteration(int healthChangeAmount);
		void revivePlayer();
		void levelCheck();
		void updatePlayerStats();
		void getPlayerXP();
	private:
		int playerHealth = 100; // Sets the player's health to 100 globally, cannot be changed as it's in private.
		int playerDamage = 5;
};
#endif