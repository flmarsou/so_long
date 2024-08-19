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

- [x] [`main`](https://github.com/flmarsou/push_swap/blob/main/src/main.c) - Checks the arguments, calls, and sends info to the [map](https://github.com/flmarsou/so_long/tree/main/src/map), [parser](https://github.com/flmarsou/so_long/tree/main/src/parser), and [display](https://github.com/flmarsou/so_long/tree/main/src/display).

## 1. Map
- [x] [`get_next_line`](https://github.com/flmarsou/so_long/blob/main/src/map/get_next_line.c) - Slightly modified version of [get_next_line](https://github.com/flmarsou/get_next_line).
- [x] [`init_map`](https://github.com/flmarsou/so_long/blob/main/src/map/init_map.c) - Initializes the struct, also allocates and assigns the map file as an array.
- [x] [`free_map`](https://github.com/flmarsou/so_long/blob/main/src/map/free_map.c) - Frees the map.

## 2. Parsing
- [x] [`is_valid_char`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_char.c) - Checks if the map file contains only correct characters (1, 0, P, C, E).
- [x] [`is_valid_count`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_count.c) - Checks and counts if there is one player, collectibles, and one exit.
- [x] [`is_valid_shape`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_shape.c) - Checks if the map is rectangular and counts its width and height.
- [x] [`is_valid_close`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_close.c) - Checks if the map is enclosed with '1' characters on all sides.
- [x] [`is_valid_path`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_path.c) - Checks if the map is possible *(if the player can reach all collectibles and exit)* using the **Flood Fill** algorithm.

## 3. Display

## X. Utils
- [x] [`ft_printf`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_printf.c) - Slightly modified version of [ft_printf](https://github.com/flmarsou/ft_printf).
- [x] [`ft_putchar`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_putchar.c) - Prints a character.
- [x] [`ft_putstr`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_putstr.c) - Prints a string.
- [x] [`ft_puterr`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_puterr.c) - Prints a string and exit the program.
- [x] [`ft_putnbr`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_putnbr.c) - Prints an integer.
- [x] [`ft_putuni`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_putuni.c) - Prints an unsigned integer.
- [x] [`ft_strchr`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_strchr.c) - Searches for a character in a string.
- [x] [`ft_strcmp`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_strcmp.c) - Checks for a difference between two strings.
- [x] [`ft_strdup`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_strdup.c) - Duplicates and allocates a string.
- [x] [`ft_strjoin`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_strjoin.c) - Concatenates two strings.
- [x] [`ft_strlen`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_strlen.c) - Returns the length of a string.
