/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:09 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/23 15:43:51 by flmarsou         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
}			t_map;

// Utils
void		ft_putstr(const char *str);
void		ft_puterr(const char *str);
int			ft_strlen(const char *str);
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strchr(char *str, char target);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *str1, char *str2);

// Map
t_map		init_map(const char **argv);
char		*get_next_line(int fd);
void		parse_map(t_map map);

#endif
