/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:24:13 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/17 20:42:47 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_args(int argc, const char **argv)
{
	int	fd;

	if (argc == 1 || argv[1][0] == '\0')
		ft_puterr("Too Few Argument!");
	if (argc > 2)
		ft_puterr("Too Many Arguments!");
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber") != 0)
		ft_puterr("Wrong Argument!");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_puterr("File Not Found!");
	else
		close(fd);
}

void	init_map(int argc, const char **argv)
{
	check_args(argc, argv);
}