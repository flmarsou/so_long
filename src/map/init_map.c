/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:24:13 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/22 15:45:32 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	count_line(int fd)
{
	int		count;
	char	buffer;
	int		byte_read;

	count = 0;
	buffer = 0;
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, &buffer, 1);
		if (buffer == '\n')
			count++;
	}
	if (buffer != '\n' && byte_read == 0)
		count++;
	return (count);
}

void	init_map(const char **argv, int fd)
{
	char	**arr;
	char	*line;
	int		i;

	(void)argv;
	arr = (char **)malloc(sizeof(char *) * (count_line(fd) + 1));
	if (!arr)
		ft_puterr("Allocation Failed! [./src/map/init_map]");
	// Todo: Need to "reset" the FD here because of the read() in count_line().
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		arr[i] = line;
		i++;
		line = get_next_line(fd);
	}
	arr[i] = NULL;
}
