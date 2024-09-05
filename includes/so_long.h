/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:09 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/05 15:54:53 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>	// write, close, read
# include <fcntl.h>		// open
# include <stdlib.h>	// malloc, free, exit
# include <math.h>		// Math Functions
# include <stdarg.h>	// Variadic Functions
# include ".MiniLibX/mlx.h"	// MiniLibX

// Hooks
# define W						119
# define ARROW_UP				65362
# define A						97
# define ARROW_LEFT				65361
# define S						115
# define ARROW_DOWN				65364
# define D						100
# define ARROW_RIGHT			65363
# define ESC					65307

// Sprites
# define TILES					48

# define WALL_BACKKGROUND		"./assets/sprites/walls/background.xpm"

# define FLOOR1					"./assets/sprites/floors/floor1.xpm"
# define FLOOR2					"./assets/sprites/floors/floor2.xpm"
# define FLOOR3					"./assets/sprites/floors/floor3.xpm"
# define FLOOR4					"./assets/sprites/floors/floor4.xpm"

# define PLAYER_UP				"./assets/sprites/players/player_up.xpm"
# define PLAYER_DOWN			"./assets/sprites/players/player_down.xpm"
# define PLAYER_LEFT			"./assets/sprites/players/player_left.xpm"
# define PLAYER_RIGHT			"./assets/sprites/players/player_right.xpm"

# define EXIT1					"./assets/sprites/exits/exit1.xpm"
# define EXIT2					"./assets/sprites/exits/exit2.xpm"

// Boolean
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

// Entities Count
struct s_count
{
	unsigned int	player;
	unsigned int	collectible;
	unsigned int	exit;
	unsigned int	moves;
};

// Player Position
struct s_pos
{
	unsigned int	x;
	unsigned int	y;
};

// Wall Sprites
struct s_wall
{
	void			*background;
};

// Floor Sprites
struct s_floor
{
	void			*floor1;
	void			*floor2;
	void			*floor3;
	void			*floor4;
};

// Player Sprites
struct s_player
{
	void			*player_up;
	void			*player_down;
	void			*player_left;
	void			*player_right;
};

// Exit Sprites
struct s_exit
{
	void			*exit1;
	void			*exit2;
};

// MiniLibX
struct s_mlx
{
	void			*mlx;
	void			*win;
	struct s_wall	wall;
	struct s_floor	floor;
	struct s_player	player;
	struct s_exit	exit;
};

// Main Struct
typedef struct s_game
{
	struct s_count	count;
	struct s_pos	pos;
	struct s_mlx	mlx;
	char			**map;
	unsigned int	height;
	unsigned int	width;
	char			**floodfill;
	char			**map_floor;
}	t_game;

//===============================//
//             Utils             //
//===============================//

void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		ft_puterr(const char *str);
void		ft_putnbr(int nbr);
void		ft_putuni(unsigned int nbr);
void		ft_printf(const char *format, ...);
int			ft_strlen(const char *str);
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strchr(char *str, char target);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *str1, char *str2);
char		*ft_itoa(int nbr);

//===============================//
//              Map              //
//===============================//

// Returns a line one after another at each call.
char		*get_next_line(int fd);
// Allocates and turns the .ber file into an arrow of strings.
void		init_map(const char **argv, t_game *game);
// Frees the allocated char **.
void		free_map(t_game *game);

//===============================//
//            Parsing            //
//===============================//

// Checks if the map file contains only correct characters (1, 0, P, C, E).
t_bool		is_valid_char(t_game *game);

// Checks if there is one player, collectibles, and one exit.
t_bool		is_valid_count(t_game *game);

// Checks if the map is rectangular.
t_bool		is_valid_shape(t_game *game);

// Checks if the map is enclosed.
t_bool		is_valid_close(t_game *game);

// Checks if the map is possible, if player can reach all collectibles and exit.
t_bool		is_valid_path(t_game *game);

//===============================//
//            Display            //
//===============================//

// Creates the window.
void		init_display(t_game *game);
// Calls every init sprite functions.
void		init_sprites(t_game *game, int width, int height);

// Initializes wall sprites.
void		init_wall_sprites(t_game *game, int width, int height);
// Checks adjacent walls to display the correct wall sprite.
int			which_inner_wall(t_game *game, unsigned int x, unsigned int y);
// Checks diagonal walls to display the correct wall sprite.
int			which_outer_wall(t_game *game, unsigned int x, unsigned int y);
// Checks the position of the current tile and draws wall sprites in the window.
void		display_walls(t_game *game);

// Initializes floor sprites
void		init_floor_sprites(t_game *game, int width, int height);
// Generates a 2D map for randomized floor tiles.
void		which_floor(t_game *game);
// Frees 2D map.
void		floor_map_free(t_game *game);
// 	Draws floor sprites in the window.
void		draw_floor(t_game *game, char c, unsigned int x, unsigned int y);
// Checks the position of the current tile.
void		display_floors(t_game *game);

// Initializes player sprites
void		init_player_sprites(t_game *game, int width, int height);
// Draws player sprite in the window.
void		display_player(t_game *game);

// Initializes exit sprites.
void		init_exit_sprites(t_game *game, int width, int height);
// Draws exit sprites according to the collectible count.
void		display_exit(t_game *game);

//===============================//
//              Game             //
//===============================//

// Runs every time a key is pressed.
int			handle_keypress(int key, t_game *game);
// Displays text in the game window.
void		handle_text(t_game *game);

// Mananges the player movement.
void		player_move(t_game *game, unsigned int x, unsigned int y, int face);
// Manages the enemy movement.
void		enemy_move(t_game *game);

// Prints the map for debugging.
void		print_map(t_game *game);

// Frees everything and destroys the window.
int			close_window(t_game *game);

#endif
