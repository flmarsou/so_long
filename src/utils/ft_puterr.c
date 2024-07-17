/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:03:57 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/17 13:55:26 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_puterr(const char *str)
{
	ft_putstr("\e[1;31mError: \e[1;97m");
	ft_putstr(str);
	ft_putstr("\n\e[0m");
	exit(1);
}
