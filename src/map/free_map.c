/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:38:04 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/30 13:47:37 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->map[i])
	{
		free((void *)game->map[i]);
		i++;
	}
	free(game->map);
}
