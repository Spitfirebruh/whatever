#include "player.h" // Player Header File | Used to reference player health and damage.
#include "items.h" // NPC Header File | Used to define each Non Playable Character.
#include <iostream>
using namespace std; // Removes the need for "std::".

void invItems::itemPlaceHolder(Player& player, int id, int quantity) {
	switch (id) {
	case 1:
		cout << "This is a placeholder sword!" << endl;
		break;
	case 2:
		cout << "This is a placeholder potion!" << endl;
		break;
	case 3:
		cout << "This is a placeholder temporary buff item!" << endl;
		break;
	default:
		cout << "The item couldn't be found [ERROR: 12 NoItemID Match]" << endl;
	}
}