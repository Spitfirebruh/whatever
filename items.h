// player.h | A Header File That Handles Player Attributes
#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <string>
#include "player.h"
#include <vector>
using namespace std;

class Player;

class Items {
public:
    vector<int> itemCounts;
    int id;
    string name;
    string description;
    int quantity;
    void itemsList();
    void addItem();
    void useItem();
};
#endif