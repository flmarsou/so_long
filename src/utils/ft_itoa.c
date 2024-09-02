/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:24:21 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/02 15:29:00 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	nbrlen(int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static char	*putnbr(int nbr)
{
	int		length;
	int		sign;
	char	*str;

	if (nbr < 0)
	{
		sign = 1;
		nbr *= -1;
	}
	else
		sign = 0;
	length = nbrlen(nbr) + sign;
	str = (char *)malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	length--;
	if (!str)
		return (NULL);
	while (length >= 0)
	{
		str[length--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int nbr)
{
	char	*str;

	if (nbr == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = putnbr(nbr);
	return (str);
}
