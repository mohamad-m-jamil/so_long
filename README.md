# so_long
game 2D withe C
# So Long

**So Long** is a simple 2D game built using the MiniLibX library. The goal of the game is to navigate a maze, collect items, and reach the exit while avoiding obstacles.

## Features

- **Maze Navigation:** Move around the maze using keyboard inputs.
- **Collectibles:** Gather items to complete the level.
- **Exit:** Reach the exit to finish the game.
- **Dynamic Sprites:** Animated character sprite changes based on movement.
- **Error Handling:** Comprehensive checks to ensure the map and game environment are valid.

## Installation

### Prerequisites

- [MiniLibX](https://github.com/42Paris/minilibx-linux) (or MiniLibX for macOS if applicable)
- [libft](https://github.com/42Paris/libft) (a library for standard functions)
- [get_next_line](https://github.com/42Paris/get_next_line) (for reading lines from files)

### Clone the Repository

```bash
git clone https://github.com/yourusername/so_long.git
cd so_long
```

### Compilation

Use `make` to build the project. This will compile the source files and generate an executable named `so_long`.

```bash
make
```

### Running the Game

After compilation, run the game with a map file as an argument. The map file must have the `.ber` extension.

```bash
./so_long path/to/map.ber
```

## Map Format

The map file must adhere to the following rules:

- **Walls:** Must be enclosed by '1' (walls) on all sides.
- **Playable Area:** Empty space is represented by '0'.
- **Exit:** Represented by 'E'. There must be exactly one exit.
- **Player Start:** Represented by 'P'. There must be exactly one starting position.
- **Collectibles:** Represented by 'C'. There must be at least one collectible.
- **Invalid Characters:** Only '1', '0', 'E', 'P', and 'C' are allowed.

### Example Map

```
111111
1P000E
1C1001
1C1001
111111
```

## Controls

- **W / UP Arrow:** Move up
- **A / LEFT Arrow:** Move left
- **S / DOWN Arrow:** Move down
- **D / RIGHT Arrow:** Move right
- **ESC:** Exit the game

## Error Handling

If there are issues with the map or game environment, appropriate error messages will be displayed, and the game will exit.

## Development

### Directory Structure

- `so_long.h` - Header file containing function prototypes and structures.
- `src/` - Source files for the game logic.
- `img/` - Folder containing sprite images.
- `Makefile` - File used for compiling the project.

### Contributing

Contributions are welcome! Please open an issue or submit a pull request if you have suggestions or improvements.

### License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- MiniLibX for the graphical library
- 42 Network for the inspiration and project guidelines

---
