/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:55:19 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/26 12:43:15 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Checks if the map file contains only correct characters (1, 0, P, C, E).
static t_bool	is_valid_char(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' &&
				game->map[i][j] != 'C' && game->map[i][j] != 'P' &&
					game->map[i][j] != 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

// Checks if there is exactly one player and one exit, also counts collectibles.
static t_bool	is_valid_count(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->count.collectible++;
			if (game->map[i][j] == 'P')
				game->count.player++;
			if (game->map[i][j] == 'E')
				game->count.exit++;
			j++;
		}
		i++;
	}
	if (game->count.player != 1 || game->count.exit != 1)
		return (false);
	return (true);
}

// Checks if the map is rectangular.
static t_bool	is_valid_shape(t_game *game)
{
	unsigned int	i;
	unsigned int	height;
	unsigned int	width;

	i = 0;
	height = 0;
	width = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != 0)
		{
			if ((unsigned int)ft_strlen(game->map[i]) != width)
				return (false);
			height++;
		}
		i++;
	}
	game->height = height;
	game->width = width;
	return (true);
}

// Checks if the map is enclosed.
static t_bool	is_valid_close(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (game->map[game->height - 1][i])
	{
		if (game->map[game->height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	parse_map(t_game *game)
{
	if (!is_valid_char(game))
		ft_puterr("Invalid characters in map!", 2);
	if (!is_valid_count(game))
		ft_puterr("Invalid amount of player or exit!", 2);
	if (!is_valid_shape(game))
		ft_puterr("Map has wrong shape or placement!", 2);
	if (!is_valid_close(game))
		ft_puterr("Map is not enclosed!", 2);
	if (!is_valid_path(game))
		ft_puterr("Map is impossible!", 2);
}
