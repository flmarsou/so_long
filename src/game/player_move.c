/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:00:04 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/26 10:19:05 by flmarsou         ###   ########.fr       */
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

static t_bool	is_dead(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'P')
				return (false);
		}
	}
	return (true);
}

void	player_move(t_game *game, unsigned int temp_x, unsigned int temp_y)
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
		game->count.moves++;
		redraw_floor(game, player_x, player_y);
	}
	if (game->map[temp_y][temp_x] == 'E' && game->count.collectible == 0)
		close_window(game);
	if (game->map[temp_y][temp_x] == 'H' || game->map[temp_y][temp_x] == 'h'
		|| game->map[temp_y][temp_x] == 'V' || game->map[temp_y][temp_x] == 'v'
		|| is_dead(game))
		close_window(game);
}
