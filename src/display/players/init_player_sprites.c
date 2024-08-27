/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:44:42 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/27 12:47:30 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	init_player_sprites(t_game *game, int width, int height)
{
	game->mlx.player.player_up = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_UP, &width, &height);
	game->mlx.player.player_down = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_DOWN, &width, &height);
	game->mlx.player.player_left = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_LEFT, &width, &height);
	game->mlx.player.player_right = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_RIGHT, &width, &height);
}
