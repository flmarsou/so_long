/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:11:47 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/06 09:17:35 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_sprites(t_game *game, int width, int height)
{
	init_wall_sprites(game, width, height);
	init_floor_sprites(game, width, height);
	init_player_sprites(game, width, height);
	init_collectible_sprites(game, width, height);
	init_exit_sprites(game, width, height);
}
