/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:14:23 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/08 15:08:12 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_wall(t_game *game, int width, int height)
{
	game->mlx.wall.up = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_UP, &width, &height);
	game->mlx.wall.down = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_DOWN, &width, &height);
	game->mlx.wall.left = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_LEFT, &width, &height);
	game->mlx.wall.right = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_RIGHT, &width, &height);
	game->mlx.wall.up_left_corner = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_UP_LEFT_CORNER, &width, &height);
	game->mlx.wall.up_right_corner = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_UP_RIGHT_CORNER, &width, &height);
	game->mlx.wall.down_left_corner = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_DOWN_LEFT_CORNER, &width, &height);
	game->mlx.wall.down_right_corner = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_DOWN_RIGHT_CORNER, &width, &height);
	game->mlx.wall.vertical = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_VERTICAL, &width, &height);
	// game->mlx.wall.up_vertical = mlx_xpm_file_to_image(game->mlx.mlx,
	// 		WALL_UP_VERTICAL, &width, &height);
	// game->mlx.wall.down_vertical = mlx_xpm_file_to_image(game->mlx.mlx,
	// 		WALL_DOWN_VERTICAL, &width, &height);
	game->mlx.wall.background = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_BACKKGROUND, &width, &height);
}
