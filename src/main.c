/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:07:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/08/01 13:55:56 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	main_args(int argc, const char **argv)
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

static void	main_map(const char **argv, t_game *game)
{
	game->count.collectible = 0;
	game->count.player = 0;
	game->count.exit = 0;
	game->pos.x = 0;
	game->pos.y = 0;
	game->height = 0;
	game->width = 0;
	game->map = init_map(argv);
	if (!is_valid_char(game) || !is_valid_count(game)
		|| !is_valid_shape(game) || !is_valid_close(game)
		|| !is_valid_path(game))
	{
		free_map(game);
		exit (1);
	}
	free_map(game);
}

int	main(int argc, const char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (ft_puterr("Allocation Failed! [./src/map/init_map]"), 1);
	main_args(argc, argv);
	main_map(argv, game);
	free(game);
	return (0);
}
