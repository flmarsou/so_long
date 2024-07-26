/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:09 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/26 11:34:31 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>	// write, close, read
# include <fcntl.h>		// open
# include <stdlib.h>	// malloc, free, exit
# include <stdio.h>		// perror
# include <string.h>	// strerror
# include <math.h>

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

struct s_count
{
	unsigned int	player;
	unsigned int	collectible;
	unsigned int	exit;
};

struct s_pos
{
	unsigned int	x;
	unsigned int	y;
};

typedef struct s_game
{
	struct s_count	count;
	struct s_pos	pos;
	const char		**map;
	unsigned int	height;
	unsigned int	width;
	char			**floodfill;
}	t_game;

// Utils
void		ft_putstr(const char *str);
void		ft_puterr(const char *str, unsigned int error);
int			ft_strlen(const char *str);
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strchr(char *str, char target);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *str1, char *str2);

// Map
t_game		init_map(const char **argv);
char		*read_map(int fd);
void		parse_map(t_game *game);
t_bool		is_valid_path(t_game *game);

#endif
