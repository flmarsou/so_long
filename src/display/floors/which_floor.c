/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:24:58 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/05 15:54:22 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static char	pseudo_random(t_game *game)
{
	unsigned int		seed;
	static unsigned int	iteration = 0;
	unsigned int		percentage;

	seed = game->count.collectible * cos(iteration);
	seed += game->width * sin(iteration);
	seed += game->height * tan(iteration);
	iteration++;
	percentage = seed % 100;
	if (percentage < 80)
		return ('2');
	if ((seed % 3) + 1 == 1)
		return ('3');
	if ((seed % 3) + 1 == 2)
		return ('4');
	else
		return ('5');
}

static void	floor_map_replace(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map_floor[y][x] != '1')
				game->map_floor[y][x] = pseudo_random(game);
		}
	}
}

static void	floor_map_alloc(t_game *game)
{
	unsigned int	i;

	i = 0;
	game->map_floor = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map_floor)
		ft_puterr("Allocation Failed! [./src/display/which_floor]");
	while (i < game->height)
	{
		game->map_floor[i] = ft_strdup((char *)game->map[i]);
		if (!game->map_floor[i])
			ft_puterr("Allocation Failed! [./src/display/which_floor]");
		i++;
	}
	game->map_floor[i] = NULL;
}

void	floor_map_free(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->map_floor[i])
	{
		free(game->map_floor[i]);
		i++;
	}
	free(game->map_floor);
}

void	which_floor(t_game *game)
{
	floor_map_alloc(game);
	floor_map_replace(game);
}
