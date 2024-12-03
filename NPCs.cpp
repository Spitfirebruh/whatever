#include "player.h" // Player Header File | Used to reference player health and damage.
#include "enemy.h" // Enemy Header File | Used to reference enemy health and damage.
#include "NPCs.h" // NPC Header File | Used to define each Non Playable Character.
#include <iostream>
#include <random>
using namespace std; // Removes the need for "std::".

// Handles different enemy types | Assigns values based off of enemy type.
void enemyList::enemyType(Enemy& enemy, Player& player, int typeEnemy) {
	switch (typeEnemy) {
	case 1: // Enemy: Gremlin
		enemy.setName("Gremlin"); // Sets the name.
		enemy.enemyDamage = -2 - 2 * player.level; // Sets the Damage (has to be negative).
		enemy.maxEnemyHealth = 10 + 5 * player.level; // Sets the max enemy health.
		enemy.enemyHealth = enemy.maxEnemyHealth; // Sets the enemy's health to it's maximum as a starting point.
		enemy.enemHealAmount = 2 + 2 * player.level;; // Sets the enemy's heal amount.
		enemy.xpReward = 4 + player.level; // Sets the XP reward for defeating enemy.
		enemy.scoreReward = 20 + player.level; // Sets the Score reward for defeating enemy.
		enemy.isEnemyBoss = false;
		break;
	case 2: // Enemy: Meek
		enemy.setName("Meek");
		enemy.enemyDamage = -4 - 2 * player.level;
		enemy.maxEnemyHealth = 15 + 5 * player.level;
		enemy.enemyHealth = enemy.maxEnemyHealth;
		enemy.enemHealAmount = 2 + 2 * player.level;
		enemy.xpReward = 2 + player.level;
		enemy.scoreReward = 20 + player.level;
		enemy.isEnemyBoss = false;
		break;
	case 3: // Enemy: Skeleton
		enemy.setName("Sketchy");
		enemy.enemyDamage = -2 - 2 * player.level;
		enemy.maxEnemyHealth = 25 + 5 * player.level;
		enemy.enemyHealth = enemy.maxEnemyHealth;
		enemy.enemHealAmount = 0 + 2 * player.level;
		enemy.xpReward = 6 + player.level;
		enemy.scoreReward = 5 + player.level;
		enemy.isEnemyBoss = false;
		break;
	case 4: // Boss Enemy: Plink
		enemy.setName("Echo");
		enemy.enemyDamage = -4 - 2 * player.level;
		enemy.maxEnemyHealth = 20 + 5 * player.level;
		enemy.enemyHealth = enemy.maxEnemyHealth;
		enemy.enemHealAmount = 4 + 2 * player.level;;
		enemy.xpReward = 4 + player.level;
		enemy.scoreReward = 10 + player.level;
		enemy.isEnemyBoss = false;
		break;
	default:
		break;
	}
	int randomTitle = rand() % 9; // Randomly chooses a number from 0-8.
	titleClass(enemy, player, randomTitle); // Assigns randomTitle to titleClass' "title".
	cout << enemy.getName() << endl;
};


// Assigns titles | Titles affect enemy stats in various ways.
void enemyList::titleClass(Enemy& enemy, Player& player, int title) {
	int bruh = rand() % 4;
	switch (title) {
	case 0:
		enemy.setName(enemy.getName() + " The Clueless"); // Enemy Trait
		enemy.enemyAlteration = "[-2 HP]";
		enemy.maxEnemyHealth -= 2;
		enemy.enemyHealth = enemy.maxEnemyHealth;
		battleDialogue(0, 0);
		break;
	case 1:
		enemy.setName(enemy.getName() + " The Optimist"); // Enemy Trait
		enemy.enemyAlteration = "[+50% HP]";
		enemy.maxEnemyHealth *= 1.5; // Enemy Trait
		enemy.enemyHealth = enemy.maxEnemyHealth;
		battleDialogue(1, 1);
		break;
	case 2:
		enemy.setName(enemy.getName() + " The Goober"); // Enemy Trait
		enemy.enemyAlteration = "[+5 RGN]";
		enemy.enemHealAmount += 5; // Enemy Trait
		battleDialogue(2, 2);
		break;
	case 3:
		enemy.setName(enemy.getName() + " The Strong"); // Enemy Trait
		enemy.enemyAlteration = "[+2 ATK] [+25% HP]";
		enemy.enemyDamage -= 2; // Enemy Trait
		enemy.maxEnemyHealth *= 1.25;
		enemy.enemyHealth = enemy.maxEnemyHealth;
		battleDialogue(3, 3);
		break;
	case 4:
		enemy.setName(enemy.getName() + " The Rich"); // Enemy Trait
		enemy.enemyAlteration = "";
		enemy.xpReward += 5; // Enemy Trait
		enemy.scoreReward += 5; // Enemy Trait
		battleDialogue(4, 4);
		break;
	case 5:
		if (bruh > 3) {
			titleClass(enemy, player, bruh);
			break;
		}
		else if (bruh <= 3) {
			enemy.setName(enemy.getName() + " The Nested"); // Enemy Trait
			enemy.enemyAlteration = "[+15% HP] [+1 ATK]";
			enemy.enemyHealth *= 1.15;
			enemy.enemyDamage -= 1;
			enemy.xpReward += 10; // Enemy Trait
			enemy.scoreReward += 50; // Enemy Trait
			battleDialogue(5, 5);
		}
	case 6:
	case 7:
	case 8:
		enemy.setName(enemy.getName() + ""); // Enemy Trait
		enemy.enemyAlteration = "";
		battleDialogue(6, 6);
		break;
	default:
		break;
	}
};

// Chooses dialogue in battle based on 
void enemyList::battleDialogue(int win, int lose) {
	switch (lose) {
	case 0:
		winBattle = "Haha, that was too easy.";
		break;
	case 1:
		winBattle = "Was that it?";
		break;
	case 2:
		winBattle = "Hehe.";
		break;;
	case 3:
		winBattle = "Pathetic.";
		break;
	case 4:
		winBattle = "I knew I'd win, haha.";
		break;
	case 5:
		winBattle = "You did your best, unfortunately for you, it wasn't enough.";
		break;
	case 6:
		winBattle = "Imagine losing? Couldn't be me.";
		break;
	}
	switch (win) {
	case 0:
		loseBattle = "Ow, hey that hurt!";
		break;
	case 1:
		loseBattle = "I- defeated?!";
		break;
	case 2:
		loseBattle = "Aw man.";
		break;
	case 3:
		loseBattle = "You probably had to cheat, cheater.";
		break;
	case 4:
		loseBattle = "Congratulations, I guess.";
		break;
	case 5:
		loseBattle = "You did well, I commend you for that.";
		break;
	case 6:
		loseBattle = "Not fair, I was going to win that!";
		break;
	default:
		loseBattle = "Hm.";
		break;
	}
};

void enemyList::bossEndDialogue() {
    int randomDialogue = rand() % 6; // Randomly selects dialogue at initialization of boss.

    // Win dialogue: What the boss says upon defeating the player
    switch (randomDialogue) { 
    case 0:
        winBattle = "...the..void..claims..another...";
        break;
    case 1:
        winBattle = "...silence..remains...";
        break;
    case 2:
        winBattle = "...";
        break;
    case 3:
        winBattle = "...your..light..fades...";
        break;
    case 4:
        winBattle = "...all...paths...lead..here...";
        break;
    case 5:
        winBattle = "...was..this..your..best?...";
        break;
    default:
        winBattle = "...hollow..remains...";
        break;
    }
    // Lose dialogue: What the boss says when the player defeats it
    switch (randomDialogue) {
    case 0:
        loseBattle = "...even..the..void..falters...";
        break;
    case 1:
        loseBattle = "...worthy....for...now...";
        break;
    case 2:
        loseBattle = "...my purpose..unfulfilled...";
        break;
    case 3:
        loseBattle = "...you...delay the...inevitable...";
        break;
    case 4:
        loseBattle = "...from...the..ashes....we..will..rise again...";
        break;
    case 5:
        loseBattle = "...this..changes..nothing...";
        break;
    default:
        loseBattle = "...you..have..earned..this..victory...";
        break;
    }
};

void enemyList::bossType(Enemy& enemy, Player& player, int boss) {
	switch (boss) {
	case 1:
		enemy.setName("The Hollowed");
		enemy.enemyDamage = -6 - 2 * player.level;
		enemy.maxEnemyHealth = 45 + 5 * player.level;
		enemy.enemyHealth = enemy.maxEnemyHealth;
		enemy.enemHealAmount = 4 + 2 * player.level;;
		enemy.xpReward = 10 + player.level;
		enemy.scoreReward = 100 - 10 * player.level;
		enemy.isEnemyBoss = true;
		titleClass(enemy, player, 6);
		bossEndDialogue();
		break;
	default:
		break;
	}
	cout << enemy.getName() << endl;
};

void enemyList::bossBattleDialogue(Enemy& enemy, int witty) {
	switch (witty) {
	case 0:
		cout << enemy.getName() << ": ...weak..." << endl;
		break;
	case 1:
		cout << enemy.getName() << ": ...anything..more?..." << endl;
		break;
	case 2:
		cout << enemy.getName() << ": ...you're..struggling..." << endl;
		break;
	case 3:
		cout << enemy.getName() << ": ...why..persist?..." << endl;
		break;
	case 4:
		cout << enemy.getName() << ": ...you're..getting..weaker..." << endl;
		break;
	case 5:
		cout << enemy.getName() << ": ...interesting..." << endl;
		break;
	case 6:
		cout << enemy.getName() << ": ...look..behind..you..." << endl;
		break;
	case 7:
	case 8:
	case 9:
		cout << enemy.getName() << ": ..." << endl;
		break;
	case 10:
		cout << enemy.getName() << ": ...skill..issue..." << endl;
		break;
	}
};