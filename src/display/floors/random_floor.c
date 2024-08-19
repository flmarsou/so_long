/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:45:24 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/19 14:00:54 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	random_floor(t_game *game)
{
	unsigned int		seed;
	static unsigned int	iteration = 0;
	unsigned int		percentage;

	seed = game->count.collectible * cos(iteration);
	seed += game->width * sin(iteration);
	seed += game->height * tan(iteration);
	iteration++;
	percentage = seed % 100;
	if (percentage < 80)
		return (0);
	return ((seed % 3) + 1);
}
