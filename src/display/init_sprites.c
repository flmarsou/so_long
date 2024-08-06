/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:14:23 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/06 14:49:15 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_wall(t_game *game, int width, int height)
{
	// Upper Wall
	game->mlx.xpm_upper_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			UPPER_WALL, &width, &height);

	// Lower Wall
	game->mlx.xpm_lower_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			LOWER_WALL, &width, &height);

	// Upper Left Corner Wall
	game->mlx.xpm_upper_lc_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			UPPER_LC_WALL, &width, &height);
	
	// Upper Right Corner Wall
	game->mlx.xpm_upper_rc_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			UPPER_RC_WALL, &width, &height);

	// Lower Left Corner Wall
	game->mlx.xpm_lower_lc_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			LOWER_LC_WALL, &width, &height);
	
	// Lower Right Corner Wall
	game->mlx.xpm_lower_rc_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			LOWER_RC_WALL, &width, &height);

	// Horizontal Wall
	game->mlx.xpm_left_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			LEFT_WALL, &width, &height);

	// Vertical Wall
	game->mlx.xpm_right_wall = mlx_xpm_file_to_image(game->mlx.mlx,
			RIGHT_WALL, &width, &height);
}
