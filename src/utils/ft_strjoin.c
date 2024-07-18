/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:24:47 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/18 09:32:16 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	j = -1;
	ret = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (ret == NULL)
		return (NULL);
	while (str1[++i])
		ret[i] = str1[i];
	while (str2[++j])
		ret[i + j] = str2[j];
	ret[i + j] = '\0';
	return (ret);
}
