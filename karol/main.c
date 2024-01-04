/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchrosci <kchrosci@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 05:46:25 by kchrosci      #+#    #+#                 */
/*   Updated: 2023/12/30 23:31:50 by kchrosci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perror_exit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	mlx_destroy_exit(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	free_info(info);
	exit(EXIT_SUCCESS);
}

static int	main_loop(t_info *info)
{
	draw_floor_ceil(info);
	raycast(info);
	draw_map(info);
	return (0);
}

int	main(int ac, char **av)
{
	t_parse	parse;
	t_info	info;

	if (ac != 2)
		perror_exit("argument error");
	if (check_cub(&parse, av[1]) == -1)
		perror_exit("infile error");
	init_data(&parse, &info);
	if (check_element(&parse, &info) == -1)
		perror_exit("element error");
	if (texture_path_check(&parse, &info) == -1)
		perror_exit("texture path error");
	if (check_map(&parse, &info) == -1)
		perror_exit("map error");
	if (check_map2(&parse, &info) == -1)
		perror_exit("map2 error");
	free_parse(&parse);
	init(&info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_key_hook(info.win, key_press, &info);
	mlx_loop(info.mlx);
	return (0);
}
