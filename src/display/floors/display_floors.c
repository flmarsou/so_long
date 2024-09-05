/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_floors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:36:57 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/05 15:40:56 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	draw_floor(t_game *game, char c, unsigned int x, unsigned int y)
{
	if (c == '2')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor1, x, y);
	else if (c == '3')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor2, x, y);
	else if (c == '4')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor3, x, y);
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.floor.floor4, x, y);
}

void	display_floors(t_game *game)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	y_offset;
	unsigned int	x_offset;

	y = -1;
	y_offset = 0;
	while (++y < game->height)
	{
		x = -1;
		x_offset = 0;
		while (++x < game->width)
		{
			if (game->map[y][x] == '0')
				draw_floor(game, game->map_floor[y][x], x_offset, y_offset);
			x_offset += TILES;
		}
		y_offset += TILES;
	}
}
