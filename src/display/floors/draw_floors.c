/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:36:57 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/19 13:37:31 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	draw_floors(t_game *game)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	y_offset;
	unsigned int	x_offset;
	int				floor;

	y = -1;
	y_offset = 0;
	while (++y < game->height)
	{
		x = -1;
		x_offset = 0;
		while (++x < game->width)
		{
			if (game->map[y][x] == '0')
			{
				floor = random_floor(game);
				ft_printf("Floor Value: %d\n", floor);
			}
			x_offset += TILES;
		}
		y_offset += TILES;
	}
}
