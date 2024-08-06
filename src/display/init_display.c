/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:55:37 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/06 14:14:59 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_display(t_game *game)
{
	int	width;
	int	height;

	width = TILES;
	height = TILES;
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		ft_puterr("Failed to initialize MLX!");
	game->mlx.win = mlx_new_window(game->mlx.mlx, game->width * TILES,
			game->height * TILES, "So Long by flmarsou");
	if (!game->mlx.win)
		ft_puterr("Failed to create window!");

	init_wall(game, TILES, TILES);

	draw_walls(game);
}

