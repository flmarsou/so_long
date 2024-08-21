/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:44:12 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/21 14:51:10 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_error(unsigned int y)
{
	ft_putstr("\e[1;31m[!] - Fail: \e[1;97m");
	ft_printf("Map has wrong shape at Y: %u", y + 1);
	ft_putstr("\n\e[0m");
}

static void	print_success(void)
{
	ft_putstr("\e[1;32m[✓] - Success: \e[1;97mis_valid_shape\n\e[0m");
}

t_bool	is_valid_shape(t_game *game)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	y;

	i = 0;
	x = ft_strlen(game->map[i]);
	y = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != 0)
		{
			if ((unsigned int)ft_strlen(game->map[i]) != x)
				return (print_error(y), false);
			y++;
		}
		i++;
	}
	game->width = x;
	game->height = y;
	return (print_success(), true);
}
