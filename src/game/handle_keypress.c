/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:18 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/05 12:38:30 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

static void	others(t_game *game)
{
	enemy_move(game);
	display_exit(game);
	handle_text(game);
	print_map(game);
	if (is_dead(game))
	{
		ft_putstr("\e[1;36m[!] - Info: \e[1;97mYou died...\n\e[0m");
		close_window(game);
	}
}

int	handle_keypress(int key, t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	x = game->pos.x;
	y = game->pos.y;
	if (key == ESC)
		close_window(game);
	if (key == W || key == ARROW_UP)
		player_move(game, x, --y, W);
	else if (key == A || key == ARROW_LEFT)
		player_move(game, --x, y, A);
	else if (key == S || key == ARROW_DOWN)
		player_move(game, x, ++y, S);
	else if (key == D || key == ARROW_RIGHT)
		player_move(game, ++x, y, D);
	else
		return (0);
	others(game);
	return (0);
}
