// menus.h | A Header File That Handles Menus
#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include <string>
#include "player.h"
#include "battle.h"
#include <vector>
using namespace std;

class BattleLoop;

class Menu {
public:
	void titleScreen(Player& player);
	void playerOptionsScreen(Player& player);
	void settings();
};
#endif