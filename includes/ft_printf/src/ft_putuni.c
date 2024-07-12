/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:08:55 by flmarsou          #+#    #+#             */
/*   Updated: 2024/06/04 12:27:35 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putuni(unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (nbr > 9)
	{
		i += ft_putuni(nbr / 10);
		i += ft_putuni(nbr % 10);
	}
	else
	{
		ft_putchr(nbr + '0');
		i++;
	}
	return (i);
}
