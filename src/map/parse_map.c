/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:55:19 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/24 16:24:27 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Checks if the map file contains only correct characters (1, 0, P, C, E).
static t_bool	ischar(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C'
			&& str[i] != 'P' && str[i] != 'E')
			return (false);
		i++;
	}
	return (true);
}

// Checks if there is only one player and exit, also counts collectibles.
static t_bool	iscount(const char *str, t_map *map)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			map->collectible++;
		if (str[i] == 'P')
			map->player++;
		if (str[i] == 'E')
			map->exit++;
		if (map->player > 1 || map->exit > 1)
			return (false);
		i++;
	}
	return (true);
}

// Checks if the map is a rectangle (ignores newlines before and after).
static t_bool	isrectangle(t_map *map)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	temp;

	i = 0;
	while (ft_strlen(map->map[i]) == 0)
		i++;
	size = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) == 0)
		{
			i++;
			continue ;
		}
		temp = ft_strlen(map->map[i]);
		if (temp != size)
			return (false);
		i++;
	}
	return (true);
}

void	parse_map(t_map *map)
{
	unsigned int	i;

	map->collectible = 0;
	map->player = 0;
	map->exit = 0;
	i = 0;
	while (map->map[i])
	{
		if (!ischar(map->map[i]))
			ft_puterr("Invalid characters in map!", 2);
		if (!iscount(map->map[i], map))
			ft_puterr("Too many players or exits!", 2);
		i++;
	}
	if (!isrectangle(map))
		ft_puterr("Map is not rectangular!", 2);
	exit(0);
}
