// Battle.cpp: Handles the turn based combat system, and handles random enemy encounters.
#include "battle.h"
#include "player.h"
#include "enemy.h"
#include "NPCs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// The Battle Loop itself
void BattleLoop::chooseTurnCombat(Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist, int currentTurn, int battleChoice, int enemyBChoice, int turnCounter) {
	int playerRun = 1; // Tracks if player has succeeded running.
	cout << string(32, '-') << endl;

	// Runs while player & enemy are alive, and when the player hasn't ran.
	while (player.getPlayerHealth() != 0 && enemy.enemyHealth != 0  && playerRun != 0) {

		// If the current turn == 1, then it's the player's turn.
		if (currentTurn == 1) {
			cout << "What will you do?\n1. Attack\n2. Block\n3. Items\n4. Run" << endl;
			cin >> battleChoice;

			// Handles non-numeric or invalid input to prevent crashes.
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << string(32, '-') << endl;

			switch (battleChoice) {
			// Player attacks.
			case 1:
				player.playerAttack(enemylist, enemy);
				currentTurn = 0; // Enemy turn
				turnCounter += 1; // Increments the turn by 1.
				break;
			
			// Player blocks, enemy deals 1/2 of it's og damage.
			case 2:
				player.playerBlock();
				currentTurn = 0; // Enemy turn
				turnCounter += 1; // Increments turn by 1
				break;

			// Player opens inventory (WIP)
			case 3:
				player.playerInventory(inventory, itemCount);
				currentTurn = 0; // Enemy turn
				turnCounter += 1; // Increments turn by 1
				break;

			// Player attempts to run from battle.
			case 4:
				if (enemy.isEnemyBoss == false) {
					playerRun = rand() % 2;
					switch (playerRun) {
					case 0:
						cout << "Player ran from the battle!" << endl;
						break;
					case 1:
						cout << "Couldn't Escape!" << endl;
						currentTurn = 0; // Enemy turn
						turnCounter += 1; // Increments turn by 1
						break;
					}
					break;
			default:
				// If the player selects an incorrect option, an error message is given.
				cout << "Please choose a valid option." << endl;
				}

				// If the enemy being fought is a boss.
				else if (enemy.isEnemyBoss == true) {
					cout << "Can't run from a boss!" << endl;
					cout << string(32, '-') << endl;

					// Special Boss dialogue
					enemylist.bossBattleDialogue(enemy, 10);
					currentTurn = 0; // Enemy turn
					turnCounter += 1; // Increments turn by 1
					break;
				}
			}
		}

		// If the current turn == 0, then it's the enemy's turn.
		// This basically handles the Enemy's rudimentary AI.
		else if (currentTurn == 0) {
			if (enemy.enemyHealth > enemy.maxEnemyHealth / 4) {
				enemyBChoice = rand() % 7;
			}
			// Enemy has a higher chance of healing and blocking at lower health.
			else if (enemy.enemyHealth < enemy.maxEnemyHealth / 4) {
				enemyBChoice = rand() % 10;
			}
			switch (enemyBChoice) {
			// Enemy attacks player.
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
				enemy.enemyAttack(enemylist, player);
				currentTurn = 1; // Player's turn
				turnCounter += 1; // Increments turn by 1.

				// Only ran if Boss is being fought and neither side has fainted, randomly selects dialogue to output.
				if (enemy.isEnemyBoss == true && enemy.enemyHealth > 0 && player.getPlayerHealth() > 0) {
					cout << string(32, '-') << endl;
					enemylist.bossBattleDialogue(enemy, enemyBChoice);
				}
				break;
			// Enemy blocks, player deals 1/2 of their og damage.
			case 5:
			case 8:
			case 9:
				enemy.enemyBlock(enemylist, turnCounter);
				currentTurn = 1; // Player's turn
				turnCounter += 1; // Increments turn by 1

				// Only ran if Boss is being fought and neither side has fainted, randomly selects dialogue to output.
				if (enemy.isEnemyBoss == true && enemy.enemyHealth > 0 && player.getPlayerHealth() > 0) {
					cout << string(32, '-') << endl;
					enemylist.bossBattleDialogue(enemy, enemyBChoice);
				}
				break;

			// Enemy heals self.
			case 6:
			case 7:
				enemy.enemyHeal(enemylist);
				currentTurn = 1; // Player's turn
				turnCounter += 1; // Increments turn by 1.

				// Only ran if Boss is being fought and neither side has fainted, randomly selects dialogue to output.
				if (enemy.isEnemyBoss == true && enemy.enemyHealth > 0 && player.getPlayerHealth() > 0) {
					cout << string(32, '-') << endl;
					enemylist.bossBattleDialogue(enemy, enemyBChoice);
				}
				break;

			// Only runs if the enemy somehow by the force of god selects an option it shouldn't. (Basically this will never be used)
			default:
				cout << "Error 01: Enemy chose an option outside the random function.\n" 
					<< player.playerName << " runs out of fear of being affected by the bug!"
					<< endl;
				playerRun = 0;
				break;
			}
		}
		cout << string(32, '-') << endl; // Just in case you wanted to know, this is a Text Border (Prints 32 of that -> -)
	}
	if (player.getPlayerHealth() == 0) {
		player.revivePlayer();
	}

	if (player.getPlayerHealth() < 0 && enemy.isEnemyBoss == true) {
		bossWinLoss = false;
	}
	else if (enemy.enemyHealth < 0 && enemy.isEnemyBoss == true) {
		bossWinLoss = true;
	}
	// Post-Battle Updates (Updates Level based on EXP; Updates Stats based on Level; Updates Rank based on Score)
	player.updateLevel();
	player.updateStats();
	player.updateRank();
};


// Chance of encountering an enemy (1/4)
void BattleLoop::diceRoll(Player& player, Enemy& enemy, Item inventory[], int& itemCount, enemyList& enemylist) {
	int chance; 

	chance = rand() % 4;
	switch (chance) {
	case 0:
	case 1:
	case 2:
		break; // Didn't encounter an enemy.
	case 3:
		int typeOEnemy = rand() % 5;
		cout << endl << string(25, '!') << endl;
		cout << "Encountered ";
		enemylist.enemyType(enemy, player, typeOEnemy);
		chooseTurnCombat(player, enemy, inventory, itemCount, enemylist, 1, 0, 0, 0); // Did encounter an enemy. (WIP)
		break;
	}
};
