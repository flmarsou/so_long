/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:36:57 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/20 13:17:48 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	draw_floor(t_game *game, int floor, unsigned int x, unsigned int y)
{
	if (floor == 0)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor1, x, y);
}

void	draw_floors(t_game *game)
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
