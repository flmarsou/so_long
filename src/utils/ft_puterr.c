/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:03:57 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/24 15:39:47 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_puterr(const char *str, unsigned int type)
{
	if (type == 1)
		ft_putstr("\e[1;31m[!] - Error: \e[1;97m");
	if (type == 2)
		ft_putstr("\e[1;35m[!] - Fail: \e[1;97m");
	ft_putstr(str);
	ft_putstr("\n\e[0m");
	exit(1);
}
