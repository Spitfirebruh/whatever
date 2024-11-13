#include "player.h" // Player Header File | Used to define player health and damage.
#include "enemy.h" // Enemy Header File | Used to reference enemy health and damage.
#include "items.h" // Items Header File | Used to reference items.
#include <iostream>
using namespace std; // Removes the need for "std::".

// Decreases the enemy's health by the player's attack. | Varies amount of damage depending on player level.
void Player::playerAttack(Enemy& enemy) {
	Player player;
	cout << "Player Attacks!" << endl;
	enemy.enemHealthDecrease(*this, playerDamage);
};

// Outputs a message that the player blocked, will have a real function in the future.
void Player::playerBlock() {
	cout << "Player Blocks!" << endl;
};

// Outputs a message that the player used an item, will have a real function in the future.
void Player::playerInventory(invItems &invitems) {
	cout << "Player Opens Inventory." << endl;
};

// Returns the Player's Health
int Player::getPlayerHealth() {
	return playerHealth;
};

// Used to decrease the player's health based on the enemy's damage.
void Player::healthAlteration(int healthChangeAmount) {
	playerHealth += healthChangeAmount;
	if (healthChangeAmount < 0) {
		cout << "Player takes " << healthChangeAmount * -1 << " damage." << endl;
	}
	else if (playerHealth >= maximumHealth) {
		playerHealth = maximumHealth;
		cout << "Player has fully healed." << endl;
	}

	if (playerHealth <= 0) {
		playerHealth = 0;
		cout << "Player Has Fainted!" << endl;
	}
	cout << "Player's Health: " << getPlayerHealth() << endl;
}

// Sets player's health back to 100.
void Player::revivePlayer() {
	cout << "Player was revived!" << endl;
	playerHealth = maximumHealth;
}

// Checks the player's health based on their
void Player::levelCheck() {
	if (exp < 10) {
		level = 1;
	}
	else if (exp >= 10 && exp < 20) {
		level = 2;
	}
	else if (exp >= 20 && exp < 50) {
		level = 3;
	}
	else if (exp >= 50 && exp < 100) {
		level = 4;
	}
	else if (exp > 100) {
		level = 5;
	}
	else {
		cout << "nuh uh" << endl;
	}

}

void Player::updatePlayerStats() {
	maximumHealth = 100 + ((level - 1) * 20);
	playerDamage = 5 + ((level - 1) * 5);
}

void Player::getPlayerXP() {
	return levelCheck();
}
