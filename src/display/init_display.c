/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:55:37 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/02 11:33:06 by flmarsou         ###   ########.fr       */
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
	game->mlx.win = mlx_new_window(game->mlx.mlx, game->width * TILES, game->height * TILES, "So_Long by flmarsou");

	init_wall(game, width, height);

    mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_wall, 100, 100);
}
