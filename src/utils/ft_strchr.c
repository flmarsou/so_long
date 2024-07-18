/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:17:55 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/18 08:35:43 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_strchr(char *str, char target)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != target)
		i++;
	if (str[i] == target)
		return (str + i);
	return (NULL);
}
