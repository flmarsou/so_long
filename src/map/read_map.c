/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:00:24 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/24 08:30:11 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	*free_var(char *buffer, char *stash)
{
	if (buffer)
		free(buffer);
	if (stash)
		free(stash);
	return (NULL);
}

static char	*get_stash(char *stash)
{
	unsigned int	i;
	unsigned int	j;
	char			*temp_stash;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free_var(NULL, stash));
	i++;
	temp_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (temp_stash == NULL)
		return (free_var(NULL, stash));
	while (stash[i])
		temp_stash[j++] = stash[i++];
	temp_stash[j] = '\0';
	free(stash);
	return (temp_stash);
}

static char	*get_line(char *stash)
{
	unsigned int	i;
	char			*line;

	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * 1 + 1);
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (!(ft_strchr(stash, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, 1);
		if (read_bytes == -1)
			return (free_var(buffer, stash));
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (temp == NULL)
			return (free_var(buffer, stash));
		free(stash);
		stash = temp;
	}
	free(buffer);
	if (read_bytes == 0 && stash[0] == '\0')
		return (free_var(NULL, stash));
	return (stash);
}

char	*read_map(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (stash == NULL)
		stash = ft_strdup("");
	stash = read_line(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	stash = get_stash(stash);
	return (line);
}
