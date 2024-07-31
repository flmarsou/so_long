# 🦊 What is So Long?

WIP

# ⚒️ Compilation

1. Run `make` to compile the program.
2. Run `make re` to recompile everything.
3. Run `./so_long <map_path>` to execute the program.

Maps can be found in the [`maps`](https://github.com/flmarsou/so_long/tree/main/maps) folder, and has to be in the `.ber` extension.
- `1`: Wall
- `0`: Floor
- `P`: Player
- `C`: Collectible
- `E`: Exit

Only the <ins>**specified characters**</ins> (e.g., walls, floors, etc.). \
Maps must be <ins>**rectangular**</ins> and <ins>**enclosed**</ins> (player cannot move outside the map area). \
Maps must contain exactly <ins>**one player**</ins> and <ins>**one exit**</ins>. \
It must be <ins>**possible to reach all collectible(s)**</ins> and <ins>**the exit**</ins> from the starting position.

# 🧼 Cleaning

1. Run `make clean` to remove every object files.
2. Run `make fclean` to remove every object files, including the executable.

# ✨ Summary

|     |     |
| --- | --- |
| Program name | so_long |
| Turn in files | Makefile, *.h, *.c, maps, sprites |
| Makefile | NAME, all, clean, fclean, re |
| Arguments | a map in format *.ber |
| External functs. | • open, close, read, write, malloc, free, perror, strerror, exit <br> • All functions of the <math.h> library <br> • All functions of the [`MiniLibX`](https://github.com/42Paris/minilibx-linux) <br> • [`ft_printf`](https://github.com/flmarsou/ft_printf)|
| [Libft](https://github.com/flmarsou/libft) authorized | Yes |
| Description | You must create a small 2D game where a player collects items before leaving the level. |

# 📑 List of Functions

## 1. Map

