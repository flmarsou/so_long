/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:55:37 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/05 16:11:12 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_map(t_game *game)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	y_offset;
	unsigned int	x_offset;
	
	y = 0;
	y_offset = 0;
	while (y < game->height)
	{
		x = 0;
		x_offset = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_wall, x_offset, y_offset);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_ground, x_offset, y_offset);
			x++;
			x_offset += TILES;
		}
		x = 0;
		y_offset += TILES;
		y++;
	}
}

void	init_display(t_game *game)
{
	int	width;
	int	height;

	width = TILES;
	height = TILES;
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx, game->width * TILES,
			game->height * TILES, "So Long by flmarsou");
	init_wall(game, TILES, TILES);
	init_ground(game, TILES, TILES);
	draw_map(game);
}
