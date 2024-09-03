/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:18 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/03 15:05:00 by flmarsou         ###   ########.fr       */
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
	enemy_move(game);
	if (key == W || key == ARROW_UP)
		player_move(game, temp_x, --temp_y, W);
	else if (key == A || key == ARROW_LEFT)
		player_move(game, --temp_x, temp_y, A);
	else if (key == S || key == ARROW_DOWN)
		player_move(game, temp_x, ++temp_y, S);
	else if (key == D || key == ARROW_RIGHT)
		player_move(game, ++temp_x, temp_y, D);
	else
		return (0);
	handle_text(game);
	return (0);
}
