// add gianluca as an easter egg that's the bad ending; alters the game to the bad ending
#include "battle.h"
#include "player.h"
#include "enemy.h"
#include "NPCs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void BattleLoop::chooseTurnCombat(Player& player, Enemy& enemy, Items& invitems, enemyList& enemylist, int currentTurn, int battleChoice, int enemyBChoice, int turnCounter) {
	int playerRun = 1;
	cout << string(32, '-') << endl;
	// Runs while the player and enemy health isn't equal to or less than 0, and while int playerRun isn't 0.
	while (player.getPlayerHealth() != 0 && enemy.enemyHealth != 0  && playerRun != 0) {
		if (currentTurn == 1) { // Player's Turn.
			cout << "What will you do?\n1. Attack\n2. Block\n3. Items\n4. Run" << endl;
			cin >> battleChoice;
			if (cin.fail()) {
				cin.clear(); // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards invalid input
			}
			cout << string(32, '-') << endl;
			switch (battleChoice) {
			case 1:
				player.playerAttack(enemylist, enemy); // Outputs a Player Attack.
				currentTurn = 0; // Sets the turn as the enemy's. 
				turnCounter += 1; // Increments the turn by 1.
				break;
			case 2:
				player.playerBlock(); // Outputs a Player Block.
				currentTurn = 0;
				turnCounter += 1;
				break;
			case 3:
				player.playerInventory(invitems); // Outputs a Player Item Use.
				currentTurn = 0;
				turnCounter += 1;
				break;
			case 4:
				if (enemy.isEnemyBoss == false) {

					playerRun = rand() % 2;
					switch (playerRun) {
					case 0:
						cout << "Player ran from the battle!" << endl;
						break;
					case 1:
						cout << "Couldn't Escape!" << endl;
						currentTurn = 0;
						turnCounter += 1;
						break;
					}
					break;
			default:
				cout << "Please choose a valid option." << endl;
				}
				else if (enemy.isEnemyBoss == true) {
					cout << "Can't run from a boss!" << endl;
					cout << string(32, '-') << endl;
					enemylist.bossBattleDialogue(enemy, 10);
					currentTurn = 0;
					turnCounter += 1;
					break;
				}
			}
		}
		else if (currentTurn == 0) { // Enemy's Turn
			// If the enemy's health is over 1/4 of it's maximum health, generates a random number from 0 to 5.
			if (enemy.enemyHealth > enemy.maxEnemyHealth / 4) {
				enemyBChoice = rand() % 7; // 0 - 6
			}
			// Elsewise, if the enemy's health is under 1/4 of it's maximum health, generates a random number from 0 to 8.
			else if (enemy.enemyHealth < enemy.maxEnemyHealth / 4) {
				enemyBChoice = rand() % 10; // 0 - 9
			}
			switch (enemyBChoice) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
				enemy.enemyAttack(enemylist, player); // Outputs an Enemy Attack.
				currentTurn = 1; // Sets the turn as the player's.
				turnCounter += 1;
				if (enemy.isEnemyBoss == true && enemy.enemyHealth > 0 && player.getPlayerHealth() > 0) {
					cout << string(32, '-') << endl;
					enemylist.bossBattleDialogue(enemy, enemyBChoice);
				}
				break;
			case 5:
			case 8:
			case 9:
				enemy.enemyBlock(enemylist, turnCounter); // Outputs an Enemy Attack.
				currentTurn = 1; // Sets the turn as the player's.
				turnCounter += 1;
				if (enemy.isEnemyBoss == true && enemy.enemyHealth > 0 && player.getPlayerHealth() > 0) {
					cout << string(32, '-') << endl;
					enemylist.bossBattleDialogue(enemy, enemyBChoice);
				}
				break;
			case 6:
			case 7:
				enemy.enemyHeal(enemylist); // Outputs an Enemy Attack.
				currentTurn = 1; // Sets the turn as the player's.
				turnCounter += 1;
				if (enemy.isEnemyBoss == true && enemy.enemyHealth > 0 && player.getPlayerHealth() > 0) {
					cout << string(32, '-') << endl;
					enemylist.bossBattleDialogue(enemy, enemyBChoice);
				}
				break;
			default:
				cout << "Undefined!" << endl;
				playerRun = 0;
				break;
			}
		}
		cout << string(32, '-') << endl;
	}
	player.updateLevel();
	player.updateStats();
	player.updateRank();
};


void BattleLoop::diceRoll(int chance) {
	chance = rand() % 4; // 0-3
	switch (chance) {
	case 1:
	case 2:
	case 3:
		break;
	case 4:
		cout << "test code" << endl;
		break;
	}
};