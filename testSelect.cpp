// add gianluca as an easter egg that's the bad ending; alters the game to the bad ending
#include "testSelect.h"
#include "player.h"
#include "enemy.h"
#include "NPCs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void testSelect::selectTestOption(Player &player, Enemy& enemy, invItems& invitems) {
	int testNum = 1;
	int choice;
	int numbEr;
	int enemyChoose;
	testSelect testSelect;
	enemyList enemylist;

	cout << "Choose An Option:\n"
		 << "1: Revive Player\n2: Simulate Battle\n"
		 <<	"3. Set Experience Points\n4. Set Enemy\n5. Player Experience\n"
		 << "6. Quit" << endl;
	while (testNum == 1) {
		cin >> choice;
		if (cin.fail()) {
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Please enter a valid number." << endl;
		}
		else {
			switch (choice) {
			case 1:
				player.revivePlayer(); // Sets the player health to 100.
				break;
			case 2: 
				testSelect.chooseTurnCombat(player, enemy, invitems, 1, 2, 3); // Simulates A Real Battle.
				break;
			case 3:
				cin >> numbEr;
				player.exp = numbEr;
				break;
			case 4:
				cout << "Who do you want to choose?\n1. glorp\n2. loaf\n3. plink boss" << endl;
				cin >> enemyChoose;
				enemylist.enemyType(enemy, player, enemyChoose);
				break;
			case 5:
				cout << "Player has " << player.exp << " xp." << endl;
				break;
			case 6:
				testNum = 0; // Stops the Test Enviorement.
				break;
			default:
				cout << "Please Select A Valid Option." << endl;
			}
		}
	}
}

void testSelect::chooseTurnCombat(Player& player, Enemy& enemy, invItems& invitems, int currentTurn, int battleChoice, int enemyBChoice) {
	enemyList enemylist;
	while (player.getPlayerHealth() != 0 && enemy.getEnemyHealth() != 0) {

		if (currentTurn == 1) { // Player's Turn.
			cout << "What will you do?\n1. Attack\n2. Block\n3. Items" << endl;
			cin >> battleChoice;

			switch (battleChoice) {
			case 1:
				player.playerAttack(enemy); // Outputs a Player Attack.
				currentTurn = 0; // Sets the turn as the enemy's.
				break;
			case 2:
				player.playerBlock(); // Outputs a Player Block.
				currentTurn = 0;
				break;
			case 3:
				player.playerInventory(invitems); // Outputs a Player Item Use.
				currentTurn = 0;
				break;
			default:
				cout << "Please choose a valid option." << endl;
			}
		}
		else if (currentTurn == 0) { // Enemy's Turn
			enemyBChoice = rand() % 4;

			switch (enemyBChoice) {
			case 1:
				enemy.enemyAttack(enemylist, player); // Outputs an Enemy Attack.
				currentTurn = 1; // Sets the turn as the player's.
				break;
			case 2:
				enemy.enemyBlock(enemylist); // Outputs an Enemy Attack.
				currentTurn = 1; // Sets the turn as the player's.
				break;
			case 3:
				enemy.enemyItemUse(enemylist); // Outputs an Enemy Attack.
				currentTurn = 1; // Sets the turn as the player's.
				break;
			default:
				cout << "Not implemented lol" << endl;
				break;
			}
		}
	}
}