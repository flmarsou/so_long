/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:00:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/26 11:55:34 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	count_text(t_game *game)
{
	unsigned int	i;
	unsigned int	j;
	char			*count;

	count = ft_itoa(game->count.moves);
	mlx_string_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
		- 68, 13, 0x555555, "Count:");
	mlx_string_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
		- 70, 11, 0xFFFFFF, "Count:");
	i = 0;
	while (++i < 33)
	{
		j = -1;
		while (++j < 11)
			mlx_pixel_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
				- 35 + i, 2 + j, 0x242630);
	}
	mlx_string_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
		- 28, 13, 0x555555, count);
	mlx_string_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
		- 30, 11, 0xFFFFFF, count);
	ft_printf("Movement Count: %s\n", count);
	free(count);
}

static void	info_text(t_game *game)
{
	mlx_string_put(game->mlx.mlx, game->mlx.win, 5, 13, 0x555555, "Keys:");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 5, 33, 0x555555, "UP    - W");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 5, 48, 0x555555, "LEFT  - A");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 5, 63, 0x555555, "DOWN  - S");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 5, 78, 0x555555, "RIGHT - D");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 5, 98, 0x555555, "RESET - R");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 3, 11, 0xFFFFFF, "Keys:");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 3, 31, 0xFFFFFF, "UP    - W");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 3, 46, 0xFFFFFF, "LEFT  - A");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 3, 61, 0xFFFFFF, "DOWN  - S");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 3, 76, 0xFFFFFF, "RIGHT - D");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 3, 96, 0xFFFFFF, "RESET - R");
}

static void	draw_box_count(t_game *game)
{
	unsigned int	i;

	i = -1;
	while (++i < 100)
	{
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
			- 72 + i, 0, 0xFFFFFF);
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
			- 72 + i, 14, 0xFFFFFF);
	}
	i = -1;
	while (++i < 14)
	{
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
			- 72, i, 0xFFFFFF);
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, (game->width * TILES)
			- 1, i, 0xFFFFFF);
	}
}

static void	draw_box_info(t_game *game)
{
	unsigned int	i;

	i = -1;
	mlx_pixel_put(game->mlx.mlx, game->mlx.win, 2, 100, 0x555555);
	mlx_pixel_put(game->mlx.mlx, game->mlx.win, 60, 2, 0x555555);
	while (++i < 60)
	{
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, i + 2, 101, 0x555555);
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, i, 0, 0xFFFFFF);
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, i, 99, 0xFFFFFF);
	}
	i = -1;
	while (++i < 99)
	{
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, 61, i + 2, 0x555555);
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, 0, i, 0xFFFFFF);
		mlx_pixel_put(game->mlx.mlx, game->mlx.win, 59, i, 0xFFFFFF);
	}
}

void	handle_text(t_game *game)
{
	draw_box_info(game);
	draw_box_count(game);
	info_text(game);
	count_text(game);
}
