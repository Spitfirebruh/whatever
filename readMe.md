# Whatever: The Game


Overall Game Summary:
- Text-Based | Exploration, Combat, Adventure |
- User traverses through a small but vast dungeon via 5 options (Go North, East, West, or South; Pickup an item if it's available to pick up).
- Locked rooms exist to encourage further exploration and more choice making.
- Each choice the user makes has a 25% chance to have them encounter an enemy.
- Battles randomly select between 4 possible enemies with 1 of 6 possible "attributes" (Affects Enemy's stats, and dialogue).
- Enemies can select between attacking, blocking, or healing in a battle (50% chance to attack, 30% chance to block, 20% chance to heal).
- Player can select between attacking, blocking, using an inventory item, or running from battle (Blocking makes an incoming attack deal 50% less damage; There's a 50% chance to either succeed or fail running from a battle).
- Player gains EXP and Score upon enemy defeat (Every 10 EXP is another "level", going up to level 10, which affects player's stats; Score is purely cosmetic and doesn't affect stats).
- Upon defeating the boss (The Hollowed), the player gains access to the end of the game.

Developers:
- Deaven Garcia: Wrote player.cpp, player.h, enemy.cpp, enemy.h, battle.cpp, battle.h, NPCS.cpp, NPCS.h, part of main.cpp
- Nathan Ege: Wrote Map.cpp, Map.h, Room.cpp, Room.h, part of main.cpp
- Johnathan Pelaez: Combined all of the above scripts.
