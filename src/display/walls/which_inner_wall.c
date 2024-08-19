/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_inner_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:50:42 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/19 12:08:47 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

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
		return (0);
	if (!top_wall && bottom_wall && !left_wall && right_wall)
		return (0);
	if (top_wall && !bottom_wall && !left_wall && right_wall)
		return (0);
	if (top_wall && !bottom_wall && left_wall && !right_wall)
		return (0);
	if (top_wall && bottom_wall && !left_wall && !right_wall)
		return (0);
	if (!top_wall && bottom_wall && !left_wall && !right_wall)
		return (0);
	if (top_wall && !bottom_wall && !left_wall && !right_wall)
		return (0);
	return (which_outer_wall(game, x, y));
}

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
		return (0);
	if (!top_wall && !bottom_wall && left_wall && right_wall)
		return (0);
	if (!top_wall && !bottom_wall && !left_wall && right_wall)
		return (0);
	if (!top_wall && !bottom_wall && left_wall && !right_wall)
		return (0);
	if (!top_wall && bottom_wall && left_wall && right_wall)
		return (0);
	if (top_wall && bottom_wall && left_wall && !right_wall)
		return (0);
	if (top_wall && bottom_wall && !left_wall && right_wall)
		return (0);
	return (which_wall2(game, x, y));
}

int	which_inner_wall(t_game *game, unsigned int x, unsigned int y)
{
	return (which_wall1(game, x, y));
}
