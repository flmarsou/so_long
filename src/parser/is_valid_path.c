/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:38:59 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/23 12:51:31 by flmarsou         ###   ########.fr       */
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
// Checks if the current position is the exit and adds to the counter.
// Checks if the current position is a wall, exit, or already visited.
// Recursively calls itself to check all four directions.
static t_bool	fill(t_game *game, unsigned int x, unsigned int y)
{
	static unsigned int	coins = 0;
	static unsigned int	exit = 0;

	if (game->floodfill[y][x] == 'C')
		coins++;
	if (game->floodfill[y][x] == 'E')
		exit++;
	if (exit && coins == game->count.collectible)
		return (true);
	if (game->floodfill[y][x] == '1' || game->floodfill[y][x] == 'E'
		|| game->floodfill[y][x] == 'F')
		return (false);
	game->floodfill[y][x] = 'F';
	if (fill(game, x + 1, y) || fill(game, x, y + 1)
		|| fill(game, x - 1, y) || fill(game, x, y - 1))
		return (true);
	return (false);
}

// Finds player's position to start the pathfinding.
static t_bool	floodfill(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->floodfill[y][x] == 'P')
			{
				game->pos.x = x;
				game->pos.y = y;
				return (fill(game, game->pos.x, game->pos.y));
			}
			x++;
		}
		y++;
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
		ft_puterr("Allocation Failed! [./src/map/path_map]");
	while (i < height)
	{
		game->floodfill[i] = ft_strdup((char *)game->map[i]);
		if (!game->floodfill[i])
			ft_puterr("Allocation Failed! [./src/map/path_map]");
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
	if (!valid)
		ft_putstr("\e[1;31m[!] - Fail: \e[1;97mMap is not possible!\n\e[0m");
	else
		ft_putstr("\e[1;32m[✓] - Success: \e[1;97mis_valid_path\n\e[0m");
	return (valid);
}
