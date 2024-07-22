/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:07:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/22 15:32:33 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_args(int argc, const char **argv, int fd)
{
	if (argc == 1 || argv[1][0] == '\0')
		ft_puterr("Too Few Argument!");
	if (argc > 2)
		ft_puterr("Too Many Arguments!");
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber"))
		ft_puterr("Wrong Argument!");
	if (fd == -1)
		ft_puterr("File Not Found!");
}

int	main(int argc, const char **argv)
{
	int	fd;
	
	fd = open(argv[1], O_RDONLY);
	check_args(argc, argv, fd);
	init_map(argv, fd);
	return (0);
}
