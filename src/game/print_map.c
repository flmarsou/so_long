/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:38:47 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/05 13:47:43 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <termios.h>

static void	print_char(char c)
{
	
	if (c == '1')
		ft_printf("\e[48;2;0;0;0m  ");
	else if (c == '0')
		ft_printf("\e[48;2;255;255;255m  ");
	else if (c == 'P')
		ft_printf("\e[1;48;2;0;200;0m  ");
	else if (c == 'C')
		ft_printf("\e[1;48;2;255;215;0m  ");
	else if (c == 'E')
		ft_printf("\e[1;48;2;215;0;0m  ");
	else if (c == 'H')
		ft_printf("\e[48;2;200;0;100m  ");
	else if (c == 'h')
		ft_printf("\e[48;2;200;0;100m  ");
	else if (c == 'V')
		ft_printf("\e[48;2;200;0;100m  ");
	else if (c == 'v')
		ft_printf("\e[48;2;200;0;100m  ");
}

void	print_map(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
			print_char(game->map[y][x]);
		ft_printf("\e[0m\n");
	}
	ft_printf("\e[0m\n");
}
