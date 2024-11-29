#include "enemy.h"
#include "player.h"
#include "NPCs.h"
#include <iostream>
using namespace std;

void Enemy::enemyAttack(enemyList &enemylist, Player& player) {
	cout << getName() << " Attacks!" << endl;
	if (player.isPlayerBlocking == false) {
		player.healthAlteration(*this, enemylist, enemyDamage);
	}
	else if (player.isPlayerBlocking == true) {
		player.healthAlteration(*this, enemylist, enemyDamage / 2);
		player.isPlayerBlocking = false;
	}
};

void Enemy::enemyBlock(enemyList& enemylist, int checkTurn) {
	cout << getName() << " Blocks!" << endl;
	if (disableNotification == false) {
		cout << "(Your next attack will deal 50% less damage!)" << endl;
	}
	EnemyIsBlocking = true;
};

void Enemy::enemyHeal(enemyList& enemylist) {
	cout << getName() << " heals for " << enemHealAmount << " health." << endl;
	enemyHealthBar();
	enemyHealth += enemHealAmount;
	if (enemyHealth > maxEnemyHealth) {
		enemyHealth = maxEnemyHealth;
	}
};

void Enemy::enemHealthDecrease(Player& player, enemyList& enemylist, int playerDamageAmount) {
	cout << getName() << " takes " << playerDamageAmount << " damage." << endl;
	enemyHealth -= playerDamageAmount;
	if (enemyHealth <= 0) {
		enemyHealth = 0;
	}
	enemyHealthBar();
	if (enemyHealth == 0) {
		cout << getName() << " has Fainted!" << endl;
		player.exp += xpReward;
		player.score += scoreReward;
		cout << "Player gained " << xpReward << " exp!" << endl;
		cout << string(32, '-') << endl;
		cout << getName() << ": " << enemylist.loseBattle << endl;
	}
};

void Enemy::setName(const string& name) {
	enemyName = name;
};

string Enemy::getName() const {
	return enemyName;
};

void Enemy::enemyHealthBar() {
	int spaceOfHealth = maxEnemyHealth / 2;
	int filledSegments = (enemyHealth * spaceOfHealth) / maxEnemyHealth; // Calculate filled segments
	int unfilledSegments = spaceOfHealth - filledSegments; // Calculate unfilled segments

	cout << enemyHealth << "/" << maxEnemyHealth
		<< string(spaceOfHealth - 3, ' ') << enemyAlteration << endl;
	cout << "[" 
		<< string(filledSegments, '|') 
		<< string (unfilledSegments, ' ')
		<< "]" << endl;
};