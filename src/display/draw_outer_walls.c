/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_outer_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:29:39 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/09 08:52:27 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	which_wall1(t_game *game, unsigned int x, unsigned int y)
{
	t_bool	nw_wall;
	t_bool	ne_wall;
	t_bool	sw_wall;
	t_bool	se_wall;

	nw_wall = (y == 0 || x == 0) || game->map[y - 1][x - 1] == '1';
	ne_wall = (y == 0 || x == game->width - 1) || game->map[y - 1][x + 1] == '1';
	sw_wall = (y == game->height - 1 || x == 0) || game->map[y + 1][x - 1] == '1';
	se_wall = (y == game->height - 1 || x == game->width - 1) || game->map[y + 1][x + 1] == '1';
	if (nw_wall && ne_wall && !sw_wall && !se_wall)
		return (100);
	else
		return (0);
}

int	draw_outer_walls(t_game *game, int wall, unsigned int x, unsigned int y)
{
	if (wall == 0)
		return (which_wall1(game, x, y));
	return (0);
}
