# FdF — 3D Wireframe Renderer

A program that reads a coordinates map and renders a 3D wireframe representation using isometric projection.

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

## ⌨️ Controls
Based on the current implementation, here are the available controls:
🔍 **Zoom & View**

- Mouse Scroll Up (Button 4): Zoom In.
- Mouse Scroll Down (Button 5): Zoom Out.
- ESC: Close the program.

🔄 **Rotation & Translation**

- Left / Right Arrows (L/R): Rotate the model around the Z-axis.
- Up / Down Arrows (A/D): Scale the altitude / Translate the model.

🎨 **Colors**

- C Key (99): Toggle through different background/line color presets.
- Enter Key: Cycle through additional color schemes.

## 🚀 Usage
```bash
make
./fdf test_maps/Ukraine.fdf
