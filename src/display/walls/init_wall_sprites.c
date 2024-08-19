/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:14:23 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/19 12:13:10 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	init_wall_sprites(t_game *game, int width, int height)
{
	game->mlx.wall.background = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_BACKKGROUND, &width, &height);
}
