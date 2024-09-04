/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:41:50 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/04 08:42:29 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	init_exit_sprites(t_game *game, int width, int height)
{
	game->mlx.exit.exit1 = mlx_xpm_file_to_image(game->mlx.mlx,
			EXIT1, &width, &height);
	game->mlx.exit.exit2 = mlx_xpm_file_to_image(game->mlx.mlx,
			EXIT2, &width, &height);
}
