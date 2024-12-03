#include "player.h" // Used to define player health and damage.
#include "enemy.h" // Used to reference enemy health and damage.
#include "items.h" // Used to reference items.
#include <iostream>
using namespace std; // Removes the need for "std::".

// Player's attack function
void Player::playerAttack(enemyList& enemylist, Enemy& enemy) {
	Player player;
	cout << playerName << " Attacks!" << endl;

	// Check's if enemy is blocking.
	if (enemy.EnemyIsBlocking == false) {
		enemy.enemHealthDecrease(*this, enemylist, playerDamage);
	}
	else if (enemy.EnemyIsBlocking == true) {			
		enemy.enemHealthDecrease(*this, enemylist, playerDamage / 2); // If the enemy is blocking, int playerDamage is divided by 2.
		enemy.EnemyIsBlocking = false; // Sets the enemy's block back to false.
	}
};

// Sets the isPlayerBlocking function to true, 
void Player::playerBlock() {
	cout << playerName << " Blocks!" << endl;
	isPlayerBlocking = true;
};

// Displays the player's inventory.
void Player::playerInventory(Item inventory[], int& itemCount) {
	displayInventory(inventory, itemCount);
};

void Player::useItem(Item& item, Enemy& enemy, enemyList& enemylist) {
	item.applyEffect(*this, enemy, enemylist);
};

// Returns the Player's Health
int Player::getPlayerHealth() {
	return playerHealth;
};
int Player::getPlayerDamage() {
	return playerDamage;
};


// Used to decrease the player's health based on the enemy or player action.
void Player::healthAlteration(Enemy& enemy, enemyList& enemylist, int healthChangeAmount) {
	playerHealth += healthChangeAmount; // Adds the int healthChangeAmount to int playerHealth.
	if (healthChangeAmount < 0) {
		cout << playerName << " takes " << healthChangeAmount * -1 << " damage." << endl;
	}
	else if (healthChangeAmount > 0) {
		cout << playerName << " heals " << healthChangeAmount << " HP." << endl;
	}
	else if (playerHealth >= maximumHealth) {
		playerHealth = maximumHealth;
		cout << playerName << " has fully healed." << endl;
	}
	if (playerHealth <= 0) {
		playerHealth = 0;
	}
	playerHealthBar();
	if (playerHealth == 0) {
		cout << playerName << " Has Fainted!" << endl;
		cout << string(32, '-') << endl;
		cout << enemy.getName() << ": " << enemylist.winBattle << endl;
	}
};

// Sets int playerHealth to int maximumHealth, printing a message to the console to notify the player.
void Player::revivePlayer() {
	cout << playerName << " was fully healed by a thoughtful fairy." << endl;
	playerHealth = maximumHealth;
};

// Checks the player's level based on their experience point amount.
void Player::updateLevel() {
	if (exp < 10) {
		level = 1;
	}
	else if (exp >= 10 && exp < 20) {
		level = 2;
	}
	else if (exp >= 20 && exp < 30) {
		level = 3;
	}
	else if (exp >= 30 && exp < 40) {
		level = 4;
	}
	else if (exp >= 40 && exp < 50) {
		level = 5;
	}
	else if (exp >= 50 && exp < 60) {
		level = 6;
	}
	else if (exp >= 60 && exp < 70) {
		level = 7;
	}
	else if (exp >= 70 && exp < 80) {
		level = 8;
	}
	else if (exp >= 80 && exp < 90) {
		level = 9;
	}
	else if (exp >= 90 && exp <= 100) {
		level = 10;
	}
	// If player's exp exceeds 99, sets int exp to 99.
	if (exp >= 100) {
		exp = 99;
	}

};

// Updates player's stats based on their level.
void Player::updateStats() {
	maximumHealth = 20 + ((level - 1) * 5);
	playerDamage = 4 + ((level - 1) * 2);
};

// Assigns the string rankSC a title based on the player's int score amount.
void Player::updateRank() {
	if (score < 50) {
		rankSc = "The Optimist";
	}
	else if (score >= 50 && score < 100) {
		rankSc = "The Not-So-Brave Explorer";
	}
	else if (score >= 100 && score < 150) {
		rankSc = "The Great Adventurer";
	}
	else if (score >= 150 && score < 200) {
		rankSc = "The Master Adventurer";
	}
	else if (score >= 200 && score < 250) {
		rankSc = "The Overachiever";
	}
	else if (score >= 250 && score < 400) {
		rankSc = "The Completionist";
	}
	else if (score >= 500) {
		rankSc = "The Genocider";
	}
};

void Player::playerHealthBar() {
	int spaceOfHealth = maximumHealth / 2; // Divides the maximumHealth by 2 to get the spaceOfHealth | Each bar is equal to 2 health.
	int filledSegments = (playerHealth * spaceOfHealth) / maximumHealth; // Calculates filled segments
	int unfilledSegments = spaceOfHealth - filledSegments; // Calculates unfilled segments
		// Player info.
		cout << playerHealth << "/" << maximumHealth
			 << string(spaceOfHealth - 5, ' ') << "LVL " << level << endl;
		// Player's health bar.
		cout << "["
			<< string(filledSegments, '|')
			<< string(unfilledSegments, ' ')
			<< "]" << endl;
};

void Player::applyItemAlteration(int amount) {
	if (amount == 0) {
		cout << "Don't use this function, this did literally nothing." << endl;
	}
	else if (amount < 0) {
		playerDamage += amount;
		cout << playerName << "'s ATK was temporarily decreased by " << amount << "!" << endl;
	}
	else if (amount > 0) {
		playerDamage += amount;
		cout << playerName << "'s ATK was temporarily increased by " << amount << "!" << endl;
	}
};