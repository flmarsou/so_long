/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:34:59 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/30 15:42:40 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_error(char c, unsigned int x, unsigned int y)
{
	ft_putstr("\e[1;31m[!] - Fail: \e[1;97m");
	ft_printf("Invalid character '%c' in X: %u Y: %u", c, x + 1, y + 1);
	ft_putstr("\n\e[0m");
}

t_bool	is_valid_char(t_game *game)
{
	unsigned int	x;
	unsigned int	y;
	char			c;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			c = game->map[x][y];
			if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E')
				return (print_error(c, x, y), false);
			y++;
		}
		x++;
	}
	return (true);
}