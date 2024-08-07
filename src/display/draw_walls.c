/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:50:42 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/06 17:06:53 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// static void	display_wall(t_game *game, int wall, unsigned int x, unsigned int y)
// {
// 	if (wall == 1)
// 		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_upper_lc_wall, x, y);
// 	else if (wall == 2)
// 		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_upper_wall, x, y);
// 	else if (wall == 3)
// 		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_upper_rc_wall, x, y);
// 	else if (wall == 4)
// 		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_left_wall, x, y);
// 	else if (wall == 5)
// 		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_lower_lc_wall, x, y);
// 	else if (wall == 6)
// 		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_lower_wall, x, y);
// 	else if (wall == 7)
// 		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_lower_rc_wall, x, y);
// 	else if (wall == 8)
// 		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.xpm_right_wall, x, y);
// }

// // 1: Upper Left Corner Wall
// // 2: Upper Wall
// // 3: Upper Right Corner Wall
// // 4: Left Wall
// // 5: Lower Left Corner Wall
// // 6: Lower Wall
// // 7: Lower Right Corner
// // 8: Right Wall
// static int	which_wall(t_game *game, unsigned int x, unsigned int y)
// {
// 	t_bool	top = (y == 0);
// 	t_bool	bottom = (y == game->height - 1);
// 	t_bool	left = (x == 0);
// 	t_bool	right = (x == game->width - 1);
// 	t_bool	top_wall = top || game->map[y - 1][x] == '1';
// 	t_bool	bottom_wall = bottom || game->map[y + 1][x] == '1';
// 	t_bool	left_wall = left || game->map[y][x - 1] == '1';
// 	t_bool	right_wall = right || game->map[y][x + 1] == '1';

//     if (!top_wall && !left_wall)
// 		return (1);
//     if (!top_wall && right_wall && left_wall)
// 		return (2);
//     if (!top_wall && !right_wall)
// 		return (3);
//     if (top_wall && bottom_wall && !left_wall && right_wall)
// 		return (4);
//     if (!bottom_wall && !left_wall)
// 		return (5);
//     if (!bottom_wall && right_wall && left_wall)
// 		return (6);
//     if (!bottom_wall && !right_wall)
// 		return (7);
//     if (top_wall && bottom_wall && !right_wall && left_wall)
// 		return (8);
//     return (0);
// }

// void	draw_walls(t_game *game)
// {
// 	static unsigned int	y;
// 	static unsigned int	x;
// 	static unsigned int	y_offset;
// 	static unsigned int	x_offset;

// 	y = 0;
// 	y_offset = 0;
// 	while (y < game->height)
// 	{
// 		x = 0;
// 		x_offset = 0;
// 		while (x < game->width)
// 		{
// 			if (game->map[y][x] == '1')
// 				display_wall(game, which_wall(game, x, y), x_offset, y_offset);
// 			x++;
// 			x_offset += TILES;
// 		}
// 		x = 0;
// 		y_offset += TILES;
// 		y++;
// 	}
// }
