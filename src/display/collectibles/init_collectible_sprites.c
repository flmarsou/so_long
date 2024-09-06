/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectible_sprites.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:15:48 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/06 09:12:20 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	init_collectible_sprites(t_game *game, int width, int height)
{
	game->mlx.collectible.collectible = mlx_xpm_file_to_image(game->mlx.mlx,
			COLLECTIBLE, &width, &height);
}
