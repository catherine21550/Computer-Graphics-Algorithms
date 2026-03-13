# Cub3D — Raycasting Engine

A 3D graphical project inspired by Wolfenstein 3D, built using C and the MinilibX library.

## 🕹️ Controls
- **W, A, S, D:** Move the player.
- **Left / Right Arrows:** Rotate the camera.
- **ESC / Close Window:** Exit the game.

## 🛠️ Build & Run
1. Compile the project:
   ```bash
   make

This project requires the MinilibX library. To run it on Linux (Ubuntu/Debian), you need to install the following X11 dependencies:

    sudo apt-get update
    sudo apt-get install make xorg libxext-dev libbsd-dev libx11-dev

Clone and Build MinilibX:
Bash

## Clone the official 42 Linux version
    git clone https://github.com/42Paris/minilibx-linux.git

## Build the library
    cd minilibx-linux && make

_Make sure the resulting libmlx.a is in your library path or project folder._
