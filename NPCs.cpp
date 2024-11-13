#include "player.h" // Player Header File | Used to reference player health and damage.
#include "enemy.h" // Enemy Header File | Used to reference enemy health and damage.
#include "NPCs.h" // NPC Header File | Used to define each Non Playable Character.
#include <iostream>
using namespace std; // Removes the need for "std::".

// Handles different enemy types | Assigns values based off of enemy type.
void enemyList::enemyType(Enemy &enemy, Player& player, int typeEnemy) {
	switch (typeEnemy) {
	case 1: // Enemy: Glorp
		enemy.setName("glorp");
		enemy.enemyDamage = -20;
		enemy.enemyHealth = 50;
		enemy.xpReward = 5;
		break;
	case 2: // Enemy: Loaf
		enemy.setName("loaf");
		enemy.enemyDamage = -10;
		enemy.enemyHealth = 75;
		enemy.xpReward = 5;
		break;
	case 3: // Boss Enemy: Plink
		enemy.setName("plink");
		enemy.enemyDamage = -30;
		enemy.enemyHealth = 150;
		enemy.xpReward = 10;
		break;
	default:
		cout << "Select a valid enemy." << endl;
	}
	int randomTitle = rand() % 3; // Randomly chooses a number from 0-2.
	titleClass(enemy, player, randomTitle); // Assigns randomTitle to titleClass' "title".
	cout << enemy.getName() << endl;
}


// Assigns titles | Titles affect enemy stats in various ways.
void enemyList::titleClass(Enemy& enemy, Player& player, int title) {
	switch (title) {
	case 1:
		enemy.setName(enemy.getName() + " the clueless"); // Enemy Trait
		enemy.enemyHealth -= 5;
		break;
	case 2:
		enemy.setName(enemy.getName() + " the optimist"); // Enemy Trait
		enemy.enemyHealth -= 5; // Enemy Trait
		break;
	default:
		break;
	}
}

void enemyList::bossClass(Enemy& enemy, Player& player, int bossTitle) {
	switch (bossTitle) {
	case 1:
		enemy.setName(enemy.getName() + ": Lord of Blasphomy"); // Enemy Trait
		break;
	case 2:
		enemy.setName(enemy.getName() + ": Ponderer of Orbs."); // Enemy Trait
		break;
	default:
		break;
	}
}