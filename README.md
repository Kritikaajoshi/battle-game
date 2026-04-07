# Battleground of Bravery (C++)

## Author

Kritika Joshi

## Description

Battleground of Bravery is a terminal-based 2D combat simulation game built in C++.
The game takes place on a 7x7 grid where each cell has unique effects that can help or hinder players and enemies.

Players control characters with different weapons, movement abilities, and stats, while enemies automatically pursue and attack. Strategy is required to navigate the grid, manage combat, and survive.

## Features

* 7x7 grid-based battlefield
* Multiple character types (players and enemies)
* Different enemy tiers: Minions, Normals, Elites
* Weapon system with:

  * Dice-based damage (e.g., d4, d6, d8)
  * Hit chance percentages
  * Range types (Melee, Short, Medium, Long)
* Cell effects system (buffs and debuffs)
* Turn-based combat system
* Enemy AI that targets closest player
* Game summary output at the end

## How to Compile

```bash
g++ *.cpp -o game
```

## How to Runho

Mac/Linux:

```bash
./game
```

Windows:

```bash
game.exe
```

## Gameplay Overview

* Players and enemies take turns moving and attacking
* Movement is limited by each character’s movement stat
* Only one character can occupy a grid cell at a time
* Cell effects activate when a character steps on them
* Combat uses weapon stats, hit chance, and modifiers

## Game Modes

* Randomized initialization
* File-based initialization
* Replay option

## Winning Condition

* The game ends when one side loses all characters
* Optional: game may end after a fixed number of rounds


