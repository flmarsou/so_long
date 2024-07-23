/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:55:19 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/23 15:42:38 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Todo: Error function like Push Swap that display message, free map, exit(1).
// Fix: Newline problems.
void	parse_map(t_map map)
{
	int	size;
	int	i;

	size = ft_strlen(map.map[0]);
	i = 1;
	while (map.map[++i])
	{
		if (size != ft_strlen(map.map[i]))
			ft_puterr("Wrong Map Shape!");
	}
}
