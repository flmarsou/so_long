/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:25:36 by flmarsou          #+#    #+#             */
/*   Updated: 2024/05/14 13:19:38 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	parser(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putuni(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == '%')
		return (ft_putchr('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	total_length;
	va_list			args;

	i = 0;
	total_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total_length += parser(args, format[i]);
		}
		else
		{
			total_length += ft_putchr(format[i]);
		}
		i++;
	}
	va_end(args);
	return (total_length);
}
