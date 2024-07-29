/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:37:33 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/29 15:53:07 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Entirely frees the floodfill map once the pathfinding is complete.
static void	floodfill_free(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->floodfill[i])
	{
		free(game->floodfill[i]);
		i++;
	}
	free(game->floodfill);
}

// Checks if the current position is a coin and adds to the counter.
// Checks if the current position is the exit.
// Checks if the current position is a wall OR already visited.
// Recursively calls itself to check all four directions.
static t_bool	fill(t_game *game, unsigned int x, unsigned int y)
{
	static unsigned int	coins = 0;
	static unsigned int	exit = 0;

	if (game->floodfill[x][y] == 'C')
		coins++;
	if (game->floodfill[x][y] == 'E')
		exit++;
	if (game->floodfill[x][y] == '1' || game->floodfill[x][y] == 'X')
		return (false);
	if (exit && coins == game->count.collectible)
		return (true);
	game->floodfill[x][y] = 'X';
	if (fill(game, x + 1, y) || fill(game, x, y + 1)
		|| fill(game, x - 1, y) || fill(game, x, y - 1))
		return (true);
	return (false);
}

// Finds player's position to start the pathfinding.
static t_bool	floodfill(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->floodfill[i][j] == 'P')
			{
				game->pos.x = i;
				game->pos.y = j;
				return (fill(game, game->pos.x, game->pos.y));
			}
			j++;
		}
		i++;
	}
	return (false);
}

// Duplicates the map to be used for Flood Fill pathfinding.
static void	floodfill_alloc(t_game *game)
{
	unsigned int	i;
	unsigned int	height;

	i = 0;
	height = game->height;
	game->floodfill = (char **)malloc(sizeof(char *) * (height + 1));
	if (!game->floodfill)
		ft_puterr("Allocation Failed! [./src/map/path_map]", 1);
	while (i < height)
	{
		game->floodfill[i] = ft_strdup((char *)game->map[i]);
		if (!game->floodfill[i])
			ft_puterr("Allocation Failed! [./src/map/path_map]", 1);
		i++;
	}
	game->floodfill[i] = NULL;
}

t_bool	is_valid_path(t_game *game)
{
	t_bool	valid;

	floodfill_alloc(game);
	valid = floodfill(game);
	floodfill_free(game);
	return (valid);
}
