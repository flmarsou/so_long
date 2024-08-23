/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:58:57 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/23 13:23:08 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_v_up(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'V' && (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'P'))
			{
				game->map[y][x] = '0';
				game->map[y - 1][x] = 'V';
				draw_floor(game, random_floor(game), x * TILES, y * TILES);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->mlx.wall.background, x * TILES, (y - 1) * TILES);
			}
			else if (game->map[y][x] == 'V' && (game->map[y - 1][x] == '1' || game->map[y - 1][x] == 'C' || game->map[y - 1][x] == 'v'))
				game->map[y][x] = 'v';
		}
	}
}

static void	move_v_down(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = game->height;
	while (--y > 0)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'v' && (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'P'))
			{
				game->map[y][x] = '0';
				game->map[y + 1][x] = 'v';
				draw_floor(game, random_floor(game), x * TILES, y * TILES);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->mlx.wall.background, x * TILES, (y + 1) * TILES);
			}
			else if (game->map[y][x] == 'v' && (game->map[y + 1][x] == '1' || game->map[y + 1][x] == 'C' || game->map[y + 1][x] == 'V'))
				game->map[y][x] = 'V';
		}
	}
}

static void	move_h_left(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'H' && (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'P'))
			{
				game->map[y][x] = '0';
				game->map[y][x - 1] = 'H';
				draw_floor(game, random_floor(game), x * TILES, y * TILES);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->mlx.wall.background, (x - 1) * TILES, y * TILES);
			}
			else if (game->map[y][x] == 'H' && (game->map[y][x - 1] == '1' || game->map[y][x - 1] == 'C' || game->map[y][x - 1] == 'h'))
				game->map[y][x] = 'h';
		}
	}
}

static void	move_h_right(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < game->height)
	{
		x = game->width;
		while (--x > 0)
		{
			if (game->map[y][x] == 'h' && (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'P'))
			{
				game->map[y][x] = '0';
				game->map[y][x + 1] = 'h';
				draw_floor(game, random_floor(game), x * TILES, y * TILES);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->mlx.wall.background, (x + 1) * TILES, y * TILES);
			}
			else if (game->map[y][x] == 'h' && (game->map[y][x + 1] == '1' || game->map[y][x + 1] == 'C' || game->map[y][x + 1] == 'H'))
				game->map[y][x] = 'H';
		}
	}
}

void	enemy_move(t_game *game)
{
	move_v_up(game);
	move_v_down(game);
	move_h_left(game);
	move_h_right(game);
}
