#include "enemy.h"
#include "player.h"
#include "NPCs.h"
#include <iostream>
using namespace std;

void Enemy::enemyAttack(enemyList &enemylist, Player& player) {
	cout << getName() << " Attacks!" << endl;
	player.healthAlteration(enemyDamage);
};

void Enemy::enemyBlock(enemyList& enemylist) {
	cout << getName() << " Blocks!" << endl;
};

void Enemy::enemyItemUse(enemyList& enemylist) {
	cout << getName() << " Uses Item!" << endl;
};

int Enemy::getEnemyHealth() {
	return enemyHealth;
};

void Enemy::enemHealthDecrease(Player& player, int playerDamageAmount) {
	cout << getName() << " takes " << playerDamageAmount << " damage." << endl;
	enemyHealth -= playerDamageAmount;

	if (enemyHealth <= 0) {
		enemyHealth = 0;
		cout << getName() << " has Fainted!" << endl;
		player.exp += xpReward;
		cout << "Player gained " << xpReward << " xp!" << endl;
	}
};

void Enemy::setName(const string& name) {
	enemyName = name;
}

string Enemy::getName() const {
	return enemyName;
}