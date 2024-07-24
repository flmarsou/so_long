/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:24:13 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/24 16:02:41 by flmarsou         ###   ########.fr       */
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

t_map	init_map(const char **argv)
{
	t_map	map;
	char	*line;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	map.map = (const char **)malloc(sizeof(const char *) * (counter(fd) + 1));
	if (!map.map)
	{
		ft_puterr("Allocation Failed! [./src/map/init_map]", 1);
		close(fd);
	}
	fd = open(argv[1], O_RDONLY);
	line = read_map(fd);
	i = 0;
	while (line)
	{
		map.map[i] = line;
		i++;
		line = read_map(fd);
	}
	map.map[i] = NULL;
	close(fd);
	return (map);
}
