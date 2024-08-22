/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:18 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/22 14:51:40 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	redraw_floor(t_game *game, unsigned int x, unsigned int y)
{
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->pos.x;
	player_y = game->pos.y;
	draw_floor(game, random_floor(game), x * TILES, y * TILES);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->mlx.player.player_up, player_x * TILES, player_y * TILES);
}

static void	player_move(t_game *game, unsigned int temp_x, unsigned int temp_y)
{
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->pos.x;
	player_y = game->pos.y;
	if (game->map[temp_y][temp_x] == '0' || game->map[temp_y][temp_x] == 'C')
	{
		if (game->map[temp_y][temp_x] == 'C')
			game->count.collectible--;
		game->map[player_y][player_x] = '0';
		game->map[temp_y][temp_x] = 'P';
		game->pos.x = temp_x;
		game->pos.y = temp_y;
		redraw_floor(game, player_x, player_y);
	}
	if (game->map[temp_y][temp_x] == 'E' && game->count.collectible == 0)
		close_window(game);
}

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
	else if (key == D || key == ARROW_LEFT)
		temp_x++;
	player_move(game, temp_x, temp_y);
	return (0);
}
