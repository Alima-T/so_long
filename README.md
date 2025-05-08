# SO_LONG

## Table of Contents
- [Introduction](#introduction)
- [Objective](#objective)
- [Features](#features)
- [Instructions](#instructions)
  - [Installation](#installation)
  - [Usage](#usage)
- [Game Mechanics](#game-mechanics)
- [Evaluation Criteria](#evaluation-criteria)
- [Resources](#resources)
- [Gratitude](#gratitude)

---

## Introduction

**SO_LONG** is a 2D game project developed as part of the 42 curriculum. It challenges students to create a small graphical game using the MLX42 library. The game involves navigating a player through a map to collect items and reach the exit while avoiding obstacles.

---

## Objective

The objective of the SO_LONG project is to:
1. Learn the basics of 2D graphics programming using MLX42.
2. Implement game mechanics such as movement, collision detection, and win/lose conditions.
3. Develop skills in map parsing and handling user input.

---

## Features

- **Graphics**: Render a 2D grid-based map with textures.
- **Player Movement**: Navigate the player using keyboard inputs.
- **Collectibles**: Gather items scattered across the map.
- **Exit Mechanism**: Unlock and reach the exit after collecting all items.
- **Map Validation**: Check for valid map formats (e.g., rectangular maps, walls surrounding the map, valid characters).

---

## Instructions

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Alima-T/so_long so_long
   cd so_long
   ```
2. Compile the game:
   ```bash
   make mlx
   make
   ```

### Usage

Run the game with a valid map file:
```bash
./so_long [map_file.ber]
```
Example:
```bash
./so_long maps/map4.ber
```

### Map Format

Maps must be `.ber` files and follow these rules:
- The map must be rectangular.
- It must be surrounded by walls (`1`).
- It should contain at least one player (`P`), one exit (`E`), and one collectible (`C`).
- Only the following characters are allowed:
  - `0`: Walkable space
  - `1`: Wall
  - `P`: Player start position
  - `C`: Collectible
  - `E`: Exit
  - `S`: Enemy (bonus part)

---

## Game Mechanics

1. **Player Movement**:
   - The player can move up, down, left, and right using the keyboard arrow keys or `WASD` keys.

2. **Collectibles**:
   - Collect all items (`C`) before the exit (`E`) becomes accessible.

3. **Exit**:
   - The game ends when the player reaches the exit after collecting all items.

4. **Map Validation**:
   - The program checks for invalid maps and prints an error message if the map is not valid.

---

## Evaluation Criteria

- **Correctness**: Properly implement the game mechanics and rules.
- **Graphics**: Render the map and elements accurately using MLX42.
- **Error Handling**: Gracefully handle invalid maps or inputs.
- **Code Quality**: Follow the 42 coding standard.

---

## Resources

- [42 SO_LONG Subject](https://cdn.intra.42.fr/pdf/pdf/42187/en.subject.pdf)
- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42)
---

## Gratitude

Special gratitude to [roma-sh](https://github.com/roma-sh)
for the valuable support and feedback during the development of this project. 
Your insights and encouragement were invaluable!
