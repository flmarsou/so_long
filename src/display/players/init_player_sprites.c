/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:44:42 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/22 14:50:32 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	init_player_sprites(t_game *game, int width, int height)
{
	game->mlx.player.player_up = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_UP, &width, &height);
}
