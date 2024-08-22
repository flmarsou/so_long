/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:39:53 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/22 14:34:16 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	draw_wall1(t_game *game, int wall, unsigned int x, unsigned int y)
{
	if (wall == 0)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.background, x, y);
}

void	display_walls(t_game *game)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	y_offset;
	unsigned int	x_offset;
	int				wall;

	y = -1;
	y_offset = 0;
	while (++y < game->height)
	{
		x = -1;
		x_offset = 0;
		while (++x < game->width)
		{
			if (game->map[y][x] == '1')
			{
				wall = which_inner_wall(game, x, y);
				draw_wall1(game, wall, x_offset, y_offset);
			}
			x_offset += TILES;
		}
		y_offset += TILES;
	}
}
