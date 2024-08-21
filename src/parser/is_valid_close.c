/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:21:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/21 14:54:11 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_error(unsigned int y)
{
	ft_putstr("\e[1;31m[!] - Fail: \e[1;97mMap is not enclosed at Y: ");
	ft_printf("%u", y);
	ft_putstr("\n\e[0m");
}

static void	print_success(void)
{
	ft_putstr("\e[1;32m[✓] - Success: \e[1;97mis_valid_close\n\e[0m");
}

t_bool	is_valid_close(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (print_error(1), false);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (print_error(i + 1), false);
		i++;
	}
	i = 0;
	while (game->map[game->height - 1][i])
	{
		if (game->map[game->height - 1][i] != '1')
			return (print_error(i - 1), false);
		i++;
	}
	return (print_success(), true);
}
