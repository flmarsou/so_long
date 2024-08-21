/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:24:13 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/21 14:56:11 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	counter(int fd)
{
	int		count;
	char	buffer;
	int		byte_read;

	count = 0;
	buffer = 0;
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, &buffer, 1);
		if (buffer == '\n')
			count++;
	}
	if (buffer != '\n' && byte_read == 0)
		count++;
	close(fd);
	return (count);
}

static void	allocate_map(const char **argv, t_game *game)
{
	char		*line;
	int			i;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	game->map = (char **)malloc(sizeof(char *) * (counter(fd) + 1));
	if (!game->map)
		ft_puterr("Allocation Failed! [./src/map/init_map]");
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		game->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

void	init_map(const char **argv, t_game *game)
{
	allocate_map(argv, game);
	if (!is_valid_char(game) || !is_valid_shape(game) || !is_valid_count(game)
		|| !is_valid_close(game) || !is_valid_path(game))
	{
		free_map(game);
		free(game);
		exit(1);
	}
}
