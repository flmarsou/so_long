/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:05 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/04 08:52:24 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	destroy_exit_sprites(t_game *game)
{
	if (game->mlx.exit.exit1)
		mlx_destroy_image(game->mlx.mlx, game->mlx.exit.exit1);
	if (game->mlx.exit.exit2)
		mlx_destroy_image(game->mlx.mlx, game->mlx.exit.exit2);
}

static void	destroy_player_sprites(t_game *game)
{
	if (game->mlx.player.player_up)
		mlx_destroy_image(game->mlx.mlx, game->mlx.player.player_up);
	if (game->mlx.player.player_down)
		mlx_destroy_image(game->mlx.mlx, game->mlx.player.player_down);
	if (game->mlx.player.player_left)
		mlx_destroy_image(game->mlx.mlx, game->mlx.player.player_left);
	if (game->mlx.player.player_right)
		mlx_destroy_image(game->mlx.mlx, game->mlx.player.player_right);
}

static void	destroy_floor_sprites(t_game *game)
{
	if (game->mlx.floor.floor1)
		mlx_destroy_image(game->mlx.mlx, game->mlx.floor.floor1);
	if (game->mlx.floor.floor2)
		mlx_destroy_image(game->mlx.mlx, game->mlx.floor.floor2);
	if (game->mlx.floor.floor3)
		mlx_destroy_image(game->mlx.mlx, game->mlx.floor.floor3);
	if (game->mlx.floor.floor4)
		mlx_destroy_image(game->mlx.mlx, game->mlx.floor.floor4);
}

static void	destroy_wall_sprites1(t_game *game)
{
	if (game->mlx.wall.background)
		mlx_destroy_image(game->mlx.mlx, game->mlx.wall.background);
}

int	close_window(t_game *game)
{
	destroy_wall_sprites1(game);
	destroy_floor_sprites(game);
	destroy_player_sprites(game);
	destroy_exit_sprites(game);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	free_map(game);
	free(game);
	ft_putstr("\e[1;36m[!] - Info: \e[1;97mGame closed!\n\e[0m");
	exit(0);
}
