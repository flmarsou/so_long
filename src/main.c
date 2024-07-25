/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:07:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/25 15:34:56 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	main_args(int argc, const char **argv)
{
	int	fd;

	if (argc == 1 || argv[1][0] == '\0')
		ft_puterr("Too Few Argument!", 1);
	if (argc > 2)
		ft_puterr("Too Many Arguments!", 1);
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber"))
		ft_puterr("Wrong Argument!", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_puterr("File Not Found!", 1);
	close(fd);
}

static void	main_map(const char **argv)
{
	t_map	map;

	map.collectible = 0;
	map.player = 0;
	map.exit = 0;
	map.height = 0;
	map.width = 0;
	map = init_map(argv);
	parse_map(&map);
	exit(0);
}

int	main(int argc, const char **argv)
{
	main_args(argc, argv);
	main_map(argv);
	return (0);
}
