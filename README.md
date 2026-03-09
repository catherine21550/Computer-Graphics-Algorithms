# 🧩 Computer Graphics & Algorithms — 42 Projects

Low-level graphics and performance-oriented algorithms. Featuring a Raycasting engine (Cub3D), a 3D landscape renderer (FdF), and stack-based sorting (Push_swap). Developed at 42 Vienna.

_These projects are part of the 42 School curriculum and follow the 42 Norminette coding standard. They are intended for educational purposes and to demonstrate core engineering principles._

## 🕹️ Featured Projects

### 1. [Cub3D](./cub3d)
A 3D raycasting engine inspired by the 1992 classic *Wolfenstein 3D*.
- **Tech Stack:** C, MinilibX, Math library.
- **Key Concepts:** Perspective projection, DDA (Digital Differential Analyzer) algorithm, texture mapping, and sprite rendering.
- **The Challenge:** Handling wall collisions and ensuring smooth movement while managing real-time rendering performance.

### 2. [FdF (Fil de Fer)](./fdf)
A 3D wireframe landscape generator that parses a map and renders it in a 3D space.
- **Tech Stack:** C, MinilibX, Bresenham's algorithm.
- **Key Concepts:** Isometric projection, coordinate rotation (matrices), and color interpolation based on altitude.
- **The Challenge:** Optimizing the line-drawing algorithm to handle large datasets (maps) without flickering.

### 3. [Push_swap](./push_swap)
A highly efficient data sorting project using two stacks and a limited set of operations.
- **Tech Stack:** C, Algorithms.
- **Key Concepts:** Complexity analysis (Big O), sorting algorithms (Radix or custom greedy algorithms), and stack manipulation.
- **The Challenge:** Finding the most efficient sequence of operations to sort 100 and 500 integers within strict 42 School limits.

---

## 🛠️ Technical Skills Demonstrated
- **Low-level programming:** Manual memory management (malloc/free), pointer arithmetic, and bitwise operations.
- **Mathematics:** Linear algebra for 3D rotations, trigonometry for raycasting, and coordinate systems.
- **Algorithms:** Sorting, pathfinding, and efficient data structures.
- **System Thinking:** Building software from scratch using only a few allowed system calls.

---

## 🚀 How to Build
Each project includes a `Makefile`. To compile, navigate to the project folder and run:

```bash
make
