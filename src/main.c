/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:07:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/05 12:16:26 by flmarsou         ###   ########.fr       */
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

static void	init_struct(t_game *game)
{
	game->map = 0;
	game->height = 0;
	game->width = 0;
	game->count.player = 0;
	game->count.collectible = 0;
	game->count.exit = 0;
	game->count.moves = 0;
}

int	main(int argc, const char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (ft_puterr("Allocation Failed! [./src/map/init_map]"), 1);
	init_struct(game);
	init_map(argv, game);
	init_display(game);
	init_sprites(game, TILES, TILES);
	display_walls(game);
	display_floors(game);
	display_player(game);
	display_exit(game);
	handle_text(game);
	print_map(game);
	mlx_hook(game->mlx.win, 2, (1L << 0), handle_keypress, game);
	mlx_hook(game->mlx.win, 17, 0L, close_window, game);
	mlx_loop(game->mlx.mlx);
	return (0);
}
