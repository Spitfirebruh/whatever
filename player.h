// player.h | A Header File That Handles Player Attributes
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <fstream>
#include "enemy.h"
#include "items.h"
using namespace std;
   
class Enemy;
class Items;
class enemyList;

class Player {
	public:
		void playerAttack(enemyList& enemylist, Enemy &enemy); // Player's attack function.
		void playerBlock();	// Player's block function.
		void playerInventory(Item inventory[], int& itemCount); // Player inventory function.
		void useItem(Item& item, Enemy& enemy, enemyList& enemylist); // Function to use and apply effects of an item.
		bool isPlayerBlocking = false; // Player's block bool, if the player isn't blocking it's false, otherwise true.
		int getPlayerHealth(); // Gets the player's health.
		int level = 1; // The player's level, used to calculate stats.
		int exp = 0; // The player's experience points, used to calculate level.
		int score = 0; // The player's score, used to calculate rank.
		string rankSc; // The player's rank.
		string playerName = "placeholder_name"; // The player's name
		int maximumHealth = 20;	// The player's maximum health
		void healthAlteration(Enemy& enemy, enemyList& enemylist, int healthChangeAmount); // Alters player health.
		void revivePlayer(); // Sets player's health to maximum.
		void updateLevel();	// Updates player level.
		void updateStats(); // Updates player stats.
		void updateRank(); // Updates player rank.
		int getPlayerDamage(); // Gets player damage.
		void playerHealthBar(); // Displays player health bar.
		void applyItemAlteration(int amount); // Alters health, attack, and/or applies buffs/debuff.


        // Save game function
        void saveGame() const {
            ofstream outFile("savegame.txt");  // Open file for writing (text format)
            if (outFile.is_open()) {
                outFile << playerName << endl;
                outFile << level << endl;
                outFile << exp << endl;
                outFile << score << endl;
                outFile << maximumHealth << endl;
                outFile << playerHealth << endl;
                outFile << playerDamage << endl;
                outFile << rankSc << endl;
                outFile << isPlayerBlocking << endl;
                outFile.close();  // Close the file
            }
            else {
                cout << "Error saving game." << endl;
            }
        }

        // Load game function
        void loadGame() {
            ifstream inFile("savegame.txt");  // Open file for reading
            if (inFile.is_open()) {
                getline(inFile, playerName);  // Read player name
                inFile >> level;
                inFile >> exp;
                inFile >> score;
                inFile >> maximumHealth;
                inFile >> playerHealth;
                inFile >> playerDamage;
                inFile.ignore();  // Ignore newline character
                getline(inFile, rankSc);  // Read rank
                inFile >> isPlayerBlocking;
                inFile.close();  // Close the file
            }
            else {
                cout << "No saved game found, starting fresh!" << endl;
            }
        }

	private:
		int playerHealth = 20; // Sets the player's health.
		int playerDamage = 4; // Sets the player's damage.
};

#endif