/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:24:13 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/13 19:04:21 by flmarsou         ###   ########.fr       */
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
	game->map = 0;
	game->height = 0;
	game->width = 0;
	game->count.player = 0;
	game->count.collectible = 0;
	game->count.exit = 0;
	allocate_map(argv, game);
	if (!is_valid_count(game) || !is_valid_shape(game))
	{
		free_map(game);
		free(game);
		exit(1);
	}
}
