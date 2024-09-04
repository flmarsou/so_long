/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:44:57 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/04 08:50:23 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	which_exit(t_game *game, unsigned int x, unsigned int y)
{
	if (game->count.collectible != 0)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.exit.exit1, x, y);
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->mlx.exit.exit2, x, y);
}

void	display_exit(t_game *game)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	y_offset;
	unsigned int	x_offset;

	y = -1;
	y_offset = 0;
	while (++y < game->height)
	{
		x = -1;
		x_offset = 0;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'E')
				which_exit(game, x_offset, y_offset);
			x_offset += TILES;
		}
		y_offset += TILES;
	}
}
