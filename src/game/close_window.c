/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:05 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/22 14:47:50 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_game *game)
{
	if (game->mlx.wall.background)
		mlx_destroy_image(game->mlx.mlx, game->mlx.wall.background);
	if (game->mlx.floor.floor1)
		mlx_destroy_image(game->mlx.mlx, game->mlx.floor.floor1);
	if (game->mlx.player.player_up)
		mlx_destroy_image(game->mlx.mlx, game->mlx.player.player_up);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	free_map(game);
	free(game);
	ft_putstr("\e[1;36m[!] - Info: \e[1;97mGame closed!\n\e[0m");
	exit(0);
}
