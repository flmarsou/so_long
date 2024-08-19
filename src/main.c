/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:07:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/13 18:32:34 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_args(int argc, const char **argv)
{
	int	fd;

	if (argc == 1 || argv[1][0] == '\0')
		ft_puterr("Too Few Arguments!");
	if (argc > 2)
		ft_puterr("Too Many Arguments!");
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber"))
		ft_puterr("Wrong Argument!");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_puterr("File Not Found!");
	}
	close(fd);
}

int	main(int argc, const char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (ft_puterr("Allocation Failed! [./src/map/init_map]"), 1);
	init_map(argv, game);
	init_display(game);
	mlx_loop(game->mlx.mlx);
	free_map(game);
	free(game);
	return (0);
}
