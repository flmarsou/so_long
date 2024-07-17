/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:07:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/17 15:36:36 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void check_args(int argc, const char **argv)
{
	if (argc == 1)
		ft_puterr("Too Few Argument!");
	if (argc > 2)
		ft_puterr("Too Many Arguments!");
	if (open(argv[1], O_RDONLY) == -1)
		ft_puterr("File Not Found!");
    if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber") != 0)
        ft_puterr("Wrong Extension!");

}

int main(int argc, const char **argv)
{
	check_args(argc, argv);
	return 0;
}