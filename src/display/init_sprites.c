/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:14:23 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/02 11:32:18 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_wall(t_game *game, int *width, int *height)
{
	game->mlx.xpm_wall = mlx_xpm_file_to_image(game->mlx.mlx, SPRITE_WALL, width, height);
	if (!game->mlx.xpm_wall)
		ft_puterr("Couldn't load \"wall.xpm\" correctly!");
}
