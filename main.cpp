// pretty much everything that lets the code not have to be 1 bajillion lines
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
#include "player.h"
#include "enemy.h"
#include "testSelect.h"
#include "graphicsOverlay.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// pretty much everything that lets the code not have to be 1 bajillion lines

using namespace std;

int main() {
	menuBox graphics;
	graphics.theTitleBox();
	Player player;  // Create an instance of Player
	Enemy enemy;    // Create an instance of Enemy
	testSelect test;  // Create an instance of testSelect
	invItems invitems; // Create an instance of invItems
	test.selectTestOption(player, enemy, invitems);  // Call the function to run the selection menu
}