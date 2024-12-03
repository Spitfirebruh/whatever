#include <iostream>
#include <fstream>
#include "menus.h"

#include <limits>

#include "player.h"
#include "enemy.h"
#include "NPCs.h"
#include "Map.h"
#include "Room.h"
using namespace std;

void Menu::titleScreen(Player& player) {
    Map gameMap;                    // Initializes the game map
    int start;
    bool run = true;
    cout << R"( 
  __      __.__            __                               
 /  \    /  \  |__ _____ _/  |_  _______  __ ___________    
 \   \/\/   /  |  \\__  \\   __\/ __ \  \/ // __ \_  __ \   
  \        /|   Y  \/ __ \|  | \  ___/\   /\  ___/|  | \/   
   \__/\  / |___|  (____  /__|  \___  >\_/  \___  >__|      
        \/       \/     \/          \/          \/          
___________.__               ________                       
\__    ___/|  |__   ____    /  _____/_____    _____   ____  
  |    |   |  |  \_/ __ \  /   \  ___\__  \  /     \_/ __ \ 
  |    |   |   Y  \  ___/  \    \_\  \/ __ \|  Y Y  \  ___/ 
  |____|   |___|  /\___  >  \______  (____  /__|_|  /\___  >
                \/     \/          \/     \/      \/     \/  
    )" << endl;

    while (run == true) {
        cout << "Input a number to choose an option:\n"
            << "Start [1]\n"
            << "Settings [2]\n"
            << "Credits [3]"
            << endl;
        cin >> start;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (start) {
        case 1:
            playerOptionsScreen(player);
            run = false;
            break;
        case 2:
            break;
        case 3:
            cout << "Nah they don't deserve creidts lol." << endl;
            break;
        default:
            cout << "Please select a valid numeric option." << endl;
            break;
        }
    }
};

void Menu::playerOptionsScreen(Player& player) {
    ifstream inFile("savegame.txt");  // Check if save file exists
    if (inFile.is_open()) {
        // If the file is open, load the game data
        player.loadGame();
        cout << "Save file found. Welcome back, " << player.playerName << "!" << endl;
    }
    else {
        // If the file is not found, ask for the player's name and set stats to 0
        string name;
        cout << "No save file found. What's your name?" << endl;
        cin >> name;
        player.playerName = name;
        player.exp = 0;  // Set experience to 0
        player.score = 0;  // Set score to 0
        player.level = 1;  // Set level to 1
    }
}
void Menu::settings() {

};