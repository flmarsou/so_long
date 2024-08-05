/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:07:43 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/05 14:13:27 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_error(t_game *game)
{
	ft_putstr("\e[1;31m[!] - Fail: \e[1;97m");
	ft_putstr("Invalid amount of entities: ");
	ft_printf("- Player: %u\n", game->count.player);
	ft_printf("					- Collectible: %u\n", game->count.collectible);
	ft_printf("					- Exit: %u\n", game->count.exit);
	if (game->count.player == 0)
		ft_printf("\e[1;35m[!] - Note: \e[1;97mNo player found!\n\e[0m");
	else if (game->count.player > 1)
		ft_printf("\e[1;35m[!] - Note: \e[1;97mToo many players found!\n\e[0m");
	if (game->count.collectible < 1)
		ft_printf("\e[1;35m[!] - Note: \e[1;97mNo collectible found!\n\e[0m");
	if (game->count.exit == 0)
		ft_printf("\e[1;35m[!] - Note: \e[1;97mNo exit found!\n\e[0m");
	else if (game->count.exit > 1)
		ft_printf("\e[1;35m[!] - Note: \e[1;97mToo many exits found!\n\e[0m");
}

t_bool	is_valid_count(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->count.collectible++;
			if (game->map[y][x] == 'P')
				game->count.player++;
			if (game->map[y][x] == 'E')
				game->count.exit++;
			x++;
		}
		y++;
	}
	if (game->count.player != 1 || game->count.exit != 1
		|| game->count.collectible < 1)
		return (print_error(game), false);
	return (true);
}
