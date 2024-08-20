/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_floor_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:15:48 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/20 13:21:48 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	init_floor_sprites(t_game *game, int width, int height)
{
	game->mlx.floor.floor1 = mlx_xpm_file_to_image(game->mlx.mlx,
			FLOOR1, &width, &height);
}
