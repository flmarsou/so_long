/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:24:13 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/02 09:58:27 by flmarsou         ###   ########.fr       */
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

static const char	**allocate_map(const char **argv)
{
	const char	**map;
	char		*line;
	int			i;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	map = (const char **)malloc(sizeof(const char *) * (counter(fd) + 1));
	if (!map)
	{
		ft_puterr("Allocation Failed! [./src/map/init_map]");
		close(fd);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	init_map(const char **argv, t_game *game)
{
	game->count.collectible = 0;
	game->count.player = 0;
	game->count.exit = 0;
	game->pos.x = 0;
	game->pos.y = 0;
	game->height = 0;
	game->width = 0;
	game->map = allocate_map(argv);
	if (!is_valid_char(game) || !is_valid_count(game)
		|| !is_valid_shape(game) || !is_valid_close(game)
		|| !is_valid_path(game))
	{
		free_map(game);
		exit (1);
	}
}
