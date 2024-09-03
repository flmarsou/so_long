# 🦊 What is So Long?

**So Long** is the first graphical project of the *42 Cursus*. The objective is to create a simple **2D game** where the player navigates a *map*, collecting *items* scattered throughout the level to unlock the *exit* and complete the game. <br><br>
This project serves as a practical introduction to using **external libraries**, particularly focusing on *graphical rendering*, *window management*, and *event handling*.

### Overview:
- **Parsing:**
  > Verifies if the arguments are correct.  
  > Checks the *.ber* file by checking for [`valid characters`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_char.c), [`correct character counts`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_count.c), [`proper shape`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_shape.c), [`complete enclosure`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_close.c), and [`valid path`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_path.c), while simultaneously storing information in the struct in the process.
  
- **Initialization:**
  > Uses [get_next_line](https://github.com/flmarsou/get_next_line) to convert the *.ber* file into an **array of string**.  
  > Initializes the MLX library and creates the [display window](https://github.com/flmarsou/so_long/blob/main/src/display/init_display.c).  
  > Loads and prepares the [init_sprites](https://github.com/flmarsou/so_long/blob/main/src/display/init_sprites.c) for rendering.

- **Execution:**
  > Starts the rendering process to display the **walls**, **floors**, **collectibles**, **exit**, **player** tiles, and the in-game text.  
  > Configures the main game loop to handle user input and game events.  

# ⚒️ Compilation

1. Run `make` to compile the program.
2. Run `make re` to recompile everything.
3. Run `./so_long <map_path>` to execute the program.

Maps can be found in the [`maps`](https://github.com/flmarsou/so_long/tree/main/maps) folder, and has to be in the `.ber` extension.
| Char  | Entity |
| ----- | ------ |
|  `1`  | Wall |
|  `0`  | Floor |
|  `P`  | Player |
|  `C`  | Collectible |
|  `E`  | Exit |
|  `H`  | Horizontal Enemy |
|  `V`  | Vertical Enemy |

Only the <ins>**specified characters**</ins> (e.g., walls, floors, etc.). \
Maps must be <ins>**rectangular**</ins> and <ins>**enclosed**</ins> (player cannot move outside the map area). \
Maps must contain exactly <ins>**one player**</ins>, <ins>**one exit**</ins>, and at least <ins>**one collectible**</ins>. \
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

- [x] [`main`](https://github.com/flmarsou/so_long/blob/main/src/main.c) - Checks the arguments, calls, and sends info to the [map](https://github.com/flmarsou/so_long/tree/main/src/map), [parser](https://github.com/flmarsou/so_long/tree/main/src/parser), and [display](https://github.com/flmarsou/so_long/tree/main/src/display).

## 1. Map
- [x] [`get_next_line`](https://github.com/flmarsou/so_long/blob/main/src/map/get_next_line.c) - Slightly modified version of [get_next_line](https://github.com/flmarsou/get_next_line).
- [x] [`init_map`](https://github.com/flmarsou/so_long/blob/main/src/map/init_map.c) - Initializes the struct, allocates, and assigns the map file as an array of strings.
- [x] [`free_map`](https://github.com/flmarsou/so_long/blob/main/src/map/free_map.c)

## 2. Parsing
- [x] [`is_valid_char`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_char.c) - Checks if the map file contains only correct characters (1, 0, P, C, E).
- [x] [`is_valid_count`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_count.c) - Checks and counts if there is one player, collectibles, and one exit.
- [x] [`is_valid_shape`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_shape.c) - Checks if the map is rectangular and counts its width and height.
- [x] [`is_valid_close`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_close.c) - Checks if the map is enclosed with '1' characters on all sides.
- [x] [`is_valid_path`](https://github.com/flmarsou/so_long/blob/main/src/parser/is_valid_path.c) - Checks if the map is possible *(if the player can reach all collectibles and exit)* using the **Flood Fill** algorithm.

## 3. Display
- [x] [`init_display`](https://github.com/flmarsou/so_long/blob/main/src/display/init_display.c) - Acts as a main for the MLX's display part.
- [x] [`init_sprites`](https://github.com/flmarsou/so_long/blob/main/src/display/init_sprites.c) - Calls every functions to initialize sprites.
#### Walls:
- [x] [`display_walls`](https://github.com/flmarsou/so_long/blob/main/src/display/walls/display_walls.c) - Draws wall tiles according to their positions and neighboring tiles.
- [x] [`init_wall_sprites`](https://github.com/flmarsou/so_long/blob/main/src/display/walls/init_wall_sprites.c) - Initializes wall sprites.
- [x] [`which_inner_wall`](https://github.com/flmarsou/so_long/blob/main/src/display/walls/which_inner_wall.c) - Finds the wall sprite by checking its adjacent walls.
- [x] [`which_outer_wall`](https://github.com/flmarsou/so_long/blob/main/src/display/walls/which_outer_wall.c) - Finds the wall sprite by checking its diagonal walls.
#### Floors:
- [x] [`display_floors`](https://github.com/flmarsou/so_long/blob/main/src/display/floors/display_floors.c) - Draws floor tiles according to their positions.
- [x] [`init_floor_sprites`](https://github.com/flmarsou/so_long/blob/main/src/display/floors/init_floor_sprites.c) - Initializes floor sprites.
- [x] [`random_floor`](https://github.com/flmarsou/so_long/blob/main/src/display/floors/random_floor.c) - Returns a pseudo random seed for randomizing floor tiles.
#### Players:
- [x] [`init_player_sprites`](https://github.com/flmarsou/so_long/blob/main/src/display/players/init_player_sprites.c) - Initializes player sprites.

## 4. Game
- [x] [`handle_keypress`](https://github.com/flmarsou/so_long/blob/main/src/game/handle_keypress.c) - Runs every time a key is pressed.
- [x] [`player_move`](https://github.com/flmarsou/so_long/blob/main/src/game/player_move.c) - Manages player movements.
- [x] [`enemy_move`](https://github.com/flmarsou/so_long/blob/main/src/game/enemy_move.c) - Manages enemy movements.
- [x] [`handle_text`](https://github.com/flmarsou/so_long/blob/main/src/game/handle_text.c) - Display text in the game window.
- [x] [`close_window`](https://github.com/flmarsou/so_long/blob/main/src/game/close_window.c) - Frees everything and ends the program.

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
- [x] [`ft_itoa`](https://github.com/flmarsou/so_long/blob/main/src/utils/ft_itoa.c) - Converts an integer into a string.
