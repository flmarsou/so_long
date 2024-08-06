/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:09 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/06 16:00:05 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>	// write, close, read
# include <fcntl.h>		// open
# include <stdlib.h>	// malloc, free, exit
# include <stdio.h>		// perror
# include <string.h>	// strerror
# include <stdarg.h>	// Variadic Functions
# include ".minilibx-linux/mlx.h"	// MiniLibX

// Sprites
# define TILES	48

# define UPPER_WALL			"./assets/sprites/upper_wall.xpm"
# define LOWER_WALL			"./assets/sprites/lower_wall.xpm"
# define UPPER_LC_WALL		"./assets/sprites/upper_left_corner_wall.xpm"
# define UPPER_RC_WALL		"./assets/sprites/upper_right_corner_wall.xpm"
# define LOWER_LC_WALL		"./assets/sprites/lower_left_corner_wall.xpm"
# define LOWER_RC_WALL		"./assets/sprites/lower_right_corner_wall.xpm"
# define LEFT_WALL			"./assets/sprites/left_wall.xpm"
# define RIGHT_WALL			"./assets/sprites/right_wall.xpm"

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
};

// Player Position
struct s_pos
{
	unsigned int	x;
	unsigned int	y;
};

// MiniLibX
struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*xpm_upper_wall;
	void			*xpm_lower_wall;
	void			*xpm_upper_rc_wall;
	void			*xpm_upper_lc_wall;
	void			*xpm_lower_rc_wall;
	void			*xpm_lower_lc_wall;
	void			*xpm_left_wall;
	void			*xpm_right_wall;
};

// Main
typedef struct s_game
{
	struct s_count	count;
	struct s_pos	pos;
	struct s_mlx	mlx;
	const char		**map;
	unsigned int	height;
	unsigned int	width;
	char			**floodfill;
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

//===============================//
//              Map              //
//===============================//

char		*get_next_line(int fd);
void		init_map(const char **argv, t_game *game);
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

void		init_display(t_game *game);

void		init_wall(t_game *game, int width, int height);

void		draw_walls(t_game *game);

#endif
