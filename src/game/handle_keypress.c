/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:18 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/23 13:18:52 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_keypress(int key, t_game *game)
{
	unsigned int	temp_x;
	unsigned int	temp_y;

	temp_x = game->pos.x;
	temp_y = game->pos.y;
	if (key == ESC)
		close_window(game);
	else if (key == W || key == ARROW_UP)
		temp_y--;
	else if (key == A || key == ARROW_LEFT)
		temp_x--;
	else if (key == S || key == ARROW_DOWN)
		temp_y++;
	else if (key == D || key == ARROW_RIGHT)
		temp_x++;
	enemy_move(game);
	player_move(game, temp_x, temp_y);
	return (0);
}
