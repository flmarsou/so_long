/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:48:32 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/30 14:49:28 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_putuni(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putuni(nbr / 10);
		ft_putuni(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}
