/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:00:04 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/05 12:37:22 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	redraw(t_game *game, unsigned int x, unsigned int y, int face)
{
	draw_floor(game, random_floor(game),
		game->pos.x * TILES, game->pos.y * TILES);
	if (face == W)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.player.player_up, x * TILES, y * TILES);
	else if (face == A)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.player.player_left, x * TILES, y * TILES);
	else if (face == S)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.player.player_down, x * TILES, y * TILES);
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.player.player_right, x * TILES, y * TILES);
}

void	player_move(t_game *game, unsigned int x, unsigned int y, int face)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count.collectible--;
		game->map[game->pos.y][game->pos.x] = '0';
		game->map[y][x] = 'P';
		game->count.moves++;
		redraw(game, x, y, face);
		game->pos.x = x;
		game->pos.y = y;
	}
	if (game->map[y][x] == 'E' && game->count.collectible == 0)
	{
		ft_putstr("\e[1;36m[!] - Info: \e[1;97mYou won!\n\e[0m");
		close_window(game);
	}
	if (game->map[y][x] == 'H' || game->map[y][x] == 'h'
		|| game->map[y][x] == 'V' || game->map[y][x] == 'v')
	{
		ft_putstr("\e[1;36m[!] - Info: \e[1;97mYou died...\n\e[0m");
		close_window(game);
	}
}
