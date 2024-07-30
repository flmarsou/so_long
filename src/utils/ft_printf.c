/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:41:29 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/30 14:49:36 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	parser(va_list args, char format)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int));
	else if (format == 's')
		ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		ft_putuni(va_arg(args, unsigned int));
	else if (format == '%')
		ft_putchar('%');
}

void	ft_printf(const char *format, ...)
{
	unsigned int	i;
	va_list			args;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parser(args, format[i]);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
}
