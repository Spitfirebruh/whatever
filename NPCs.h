// player.h | A Header File That Handles Player Attributes
#ifndef NPCS_H
#define NPCS_H
#include <iostream>
#include <string>
#include "enemy.h"
using namespace std;

class Player;
class Enemy;

class enemyList {
public:
	void enemyType(Enemy &enemy, Player& player, int typeEnemy);
	void titleClass(Enemy& enemy, Player& player, int title);
	void bossClass(Enemy& enemy, Player& player, int bossTitle);
};
#endif