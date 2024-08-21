/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:18 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/21 15:29:50 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_map(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	ft_printf("Collectible Left: %u\n\n", game->count.collectible);
	ft_printf("Player X: %u\n", game->pos.x);
	ft_printf("Player Y: %u\n", game->pos.y);
	ft_putstr("\n\n\n\n\n\n\n\n\n\n");
}

static void player_movement(t_game *game, unsigned int temp_x, unsigned int temp_y)
{
	unsigned int	player_x;
	unsigned int	player_y;
	
	player_x = game->pos.x;
	player_y = game->pos.y;
	if (game->map[temp_y][temp_x] == '0' || game->map[temp_y][temp_x] == 'C')
	{
		if (game->map[temp_y][temp_x] == 'C')
			game->count.collectible--;
		game->map[player_y][player_x] = '0';
		game->map[temp_y][temp_x] = 'P';
		game->pos.x = temp_x;
		game->pos.y = temp_y;
	}
	if (game->map[temp_y][temp_x] == 'E' && game->count.collectible == 0)
		close_window(game);
}

int	handle_keypress(int key, t_game *game)
{
	unsigned int	temp_x;
	unsigned int	temp_y;

	temp_x = game->pos.x;
	temp_y = game->pos.y;
	if (key == ESC)
		close_window(game);	
	else if (key == W || key == ARROW_UP)
		temp_y--;
	else if (key == A || key == ARROW_LEFT)
		temp_x--;
	else if (key == S || key == ARROW_DOWN)
		temp_y++;
	else if (key == D || key == ARROW_LEFT)
		temp_x++;
	player_movement(game, temp_x, temp_y);
	print_map(game);
	return (0);
}
