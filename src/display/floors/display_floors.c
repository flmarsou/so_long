/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_floors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:36:57 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/03 15:11:41 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	draw_floor(t_game *game, int floor, unsigned int x, unsigned int y)
{
	if (floor == 0)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor1, x, y);
	else if (floor == 1)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor2, x, y);
	else if (floor == 2)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor3, x, y);
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor4, x, y);
}

int	random_floor(t_game *game)
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
		return (0);
	return ((seed % 3) + 1);
}

void	display_floors(t_game *game)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	y_offset;
	unsigned int	x_offset;
	int				floor;

	y = -1;
	y_offset = 0;
	while (++y < game->height)
	{
		x = -1;
		x_offset = 0;
		while (++x < game->width)
		{
			if (game->map[y][x] == '0')
			{
				floor = random_floor(game);
				draw_floor(game, floor, x_offset, y_offset);
			}
			x_offset += TILES;
		}
		y_offset += TILES;
	}
}
