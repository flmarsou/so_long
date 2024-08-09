/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:50:42 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/09 08:48:30 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_wall2(t_game *game, int wall, unsigned int x, unsigned int y)
{
	if (wall == 6)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.up_right_corner, x, y);
	else if (wall == 7)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.down_left_corner, x, y);
	else if (wall == 8)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.down_right_corner, x, y);
	else if (wall == 9)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.vertical, x, y);
	else if (wall == 10)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.background, x, y);
	else if (wall == 11)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.background, x, y);
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.vertical, x, y);
}

static void	draw_wall1(t_game *game, int wall, unsigned int x, unsigned int y)
{
	if (wall == 0)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.background, x, y);
	else if (wall == 1)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.up, x, y);
	else if (wall == 2)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.down, x, y);
	else if (wall == 3)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.left, x, y);
	else if (wall == 4)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.right, x, y);
	else if (wall == 5)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.wall.up_left_corner, x, y);
	else
		draw_wall2(game, wall, x, y);
}

/* ************************************************************************** */
/* Top Wall:	True if there is a wall above the current tile.               */
/* Bottom Wall:	True if there is a wall below the current tile.               */
/* Left Wall:	True if there is a wall to the left of the current tile.      */
/* Right Wall:	True if there is a wall to the right of the current tile.     */
/*                                                                            */
/* | 1:     1        | 2:     0        | 3:     0        | 4:     0        |  */
/* |       1X1       |       1X1       |       0X1       |       1X0       |  */
/* |        0    = 1 |        0    = 1 |        0    = 1 |        0    = 1 |  */
/*                                                                            */
/* | 5:     0        | 6:     1        | 7:     1        | 8:     0        |  */
/* |       1X1       |       1X0       |       0X1       |       1X0       |  */
/* |        1    = 2 |        1    = 3 |        1    = 4 |        1    = 5 |  */
/*                                                                            */
/* | 9:     0        | 10:    1        | 11:    1        | 12:    1        |  */
/* |       0X1       |       0X1       |       1X0       |       0X0       |  */
/* |        1    = 6 |        0    = 7 |        0    = 8 |        1    = 9 |  */
/*                                                                            */
/* | 13:    0        | 14:    1        | 15:    1        |                 |  */
/* |       0X0       |       0X0       |       1X1       |                 |  */
/* |        1   = 10 |        0   = 11 |        1    = 0 |                 |  */
/* ************************************************************************** */
static int	which_wall1(t_game *game, unsigned int x, unsigned int y)
{
	t_bool	top_wall;
	t_bool	bottom_wall;
	t_bool	left_wall;
	t_bool	right_wall;

	top_wall = (y == 0) || game->map[y - 1][x] == '1';
	bottom_wall = (y == game->height - 1) || game->map[y + 1][x] == '1';
	left_wall = (x == 0) || game->map[y][x - 1] == '1';
	right_wall = (x == game->width - 1) || game->map[y][x + 1] == '1';
	if (top_wall && !bottom_wall && left_wall && right_wall)
		return (1);
	if (!top_wall && !bottom_wall && left_wall && right_wall)
		return (1);
	if (!top_wall && !bottom_wall && !left_wall && right_wall)
		return (1);
	if (!top_wall && !bottom_wall && left_wall && !right_wall)
		return (1);
	if (!top_wall && bottom_wall && left_wall && right_wall)
		return (2);
	if (top_wall && bottom_wall && left_wall && !right_wall)
		return (3);
	if (top_wall && bottom_wall && !left_wall && right_wall)
		return (4);
	return (-1);
}

static int	which_wall2(t_game *game, unsigned int x, unsigned int y)
{
	t_bool	top_wall;
	t_bool	bottom_wall;
	t_bool	left_wall;
	t_bool	right_wall;

	top_wall = (y == 0) || game->map[y - 1][x] == '1';
	bottom_wall = (y == game->height - 1) || game->map[y + 1][x] == '1';
	left_wall = (x == 0) || game->map[y][x - 1] == '1';
	right_wall = (x == game->width - 1) || game->map[y][x + 1] == '1';
	if (!top_wall && bottom_wall && left_wall && !right_wall)
		return (5);
	if (!top_wall && bottom_wall && !left_wall && right_wall)
		return (6);
	if (top_wall && !bottom_wall && !left_wall && right_wall)
		return (7);
	if (top_wall && !bottom_wall && left_wall && !right_wall)
		return (8);
	if (top_wall && bottom_wall && !left_wall && !right_wall)
		return (9);
	if (!top_wall && bottom_wall && !left_wall && !right_wall)
		return (10);
	if (top_wall && !bottom_wall && !left_wall && !right_wall)
		return (11);
	return (draw_outer_walls(game, 0, x, y));
}

void	draw_walls(t_game *game)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	y_offset;
	unsigned int	x_offset;
	int				wall;

	y = -1;
	y_offset = 0;
	while (++y < game->height)
	{
		x = -1;
		x_offset = 0;
		while (++x < game->width)	
		{
			if (game->map[y][x] == '1')
			{
				wall = which_wall1(game, x, y);
				if (wall == -1)
					wall = which_wall2(game, x, y);
				draw_wall1(game, wall, x_offset, y_offset);
			}
			x_offset += TILES;
		}
		y_offset += TILES;
	}
}
