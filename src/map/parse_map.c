/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:55:19 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/25 15:48:08 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Checks if the map file contains only correct characters (1, 0, P, C, E).
static t_bool	is_valid_char(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j]
				!= 'C' && map->map[i][j] != 'P' && map->map[i][j] != 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

// Checks if there is exactly one player and one exit, also counts collectibles.
static t_bool	is_valid_count(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->collectible++;
			if (map->map[i][j] == 'P')
				map->player++;
			if (map->map[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	if (map->player != 1 || map->exit != 1)
		return (false);
	return (true);
}

// Checks if the map is rectangular.
static t_bool	is_valid_shape(t_map *map)
{
	unsigned int	i;
	unsigned int	height;
	unsigned int	width;

	i = 0;
	height = 0;
	width = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != 0)
		{
			if ((unsigned int)ft_strlen(map->map[i]) != width)
				return (false);
			height++;
		}
		i++;
	}
	map->height = height;
	map->width = width;
	return (true);
}

// Checks if the map is enclosed.
static t_bool	is_valid_close(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (map->map[map->height - 1][i])
	{
		if (map->map[map->height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	parse_map(t_map *map)
{
	if (!is_valid_char(map))
		ft_puterr("Invalid characters in map!", 2);
	if (!is_valid_count(map))
		ft_puterr("Invalid amount of player or exit!", 2);
	if (!is_valid_shape(map))
		ft_puterr("Map has wrong shape or placement!", 2);
	if (!is_valid_close(map))
		ft_puterr("Map is not enclosed!", 2);
}
