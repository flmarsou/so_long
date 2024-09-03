/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:00:04 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/03 15:06:53 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	redraw(t_game *game, unsigned int x, unsigned int y, int face)
{
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->pos.x;
	player_y = game->pos.y;
	draw_floor(game, random_floor(game), x * TILES, y * TILES);
	if (face == W)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.player.player_up, player_x * TILES, player_y * TILES);
	else if (face == A)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.player.player_left, player_x * TILES, player_y * TILES);
	else if (face == S)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.player.player_down, player_x * TILES, player_y * TILES);
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.player.player_right, player_x * TILES, player_y * TILES);
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

void	player_move(t_game *game, unsigned int x, unsigned int y, int face)
{
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->pos.x;
	player_y = game->pos.y;
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count.collectible--;
		game->map[player_y][player_x] = '0';
		game->map[y][x] = 'P';
		game->pos.x = x;
		game->pos.y = y;
		game->count.moves++;
		redraw(game, player_x, player_y, face);
	}
	if (game->map[y][x] == 'E' && game->count.collectible == 0)
		close_window(game);
	if (game->map[y][x] == 'H' || game->map[y][x] == 'h'
		|| game->map[y][x] == 'V' || game->map[y][x] == 'v'
		|| is_dead(game))
		close_window(game);
}
