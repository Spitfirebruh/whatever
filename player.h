// player.h | A Header File That Handles Player Attributes
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "enemy.h"
#include "items.h"
using namespace std;
   
class Enemy;
class Items;
class enemyList;

class Player {
	public:
		void playerAttack(enemyList& enemylist, Enemy &enemy);		 // Player's attack function.
		void playerBlock();						// Player's block function.
		void playerInventory(Items &invitems); // Player inventory function, calls to items.h & items.cpp.
		bool isPlayerBlocking = false;		  // If the player blocks, this is set to "true", otherwise is false.
		int getPlayerHealth();				 // Gets the player's health from the integer 'playerHealth'.
		int level = 1;						// The player's level, used to calculate the player's stats; preset to 1.
		int exp = 0;					   // The player's experience points, used to calculate the player's level; preset to 0.
		int score = 0;					  // The player's overall score, used to calculate the player's rank, displayed at the end of the game.
		string rankSc;					 // The string for the player's rank, used to describe the rank in words.
		string playerName = "placeholder_name";   // The player's name, set by the player themself.
		int maximumHealth = 20;		   // The player's maximum health, used to limit how big int playerHealth can be.
		void healthAlteration(Enemy& enemy, enemyList& enemylist, int healthChangeAmount); // Alters int playerHealth, used for enemy damage and player healing.
		void revivePlayer();		 // Sets int playerHealth to int maximumHealth.
		void updateLevel();			// 
		void updateStats();
		void updateRank();
		int getPlayerDamage();
		void playerHealthBar();
	private:
		int playerHealth = 20; // Sets the player's health to 100 globally, cannot be changed as it's in private.
		int playerDamage = 5;
};

class Menus {
public:
	void titleScreen();
	void settingsMenu();
	void blockNotification();
};
#endif