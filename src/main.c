/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 17:36:09 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/10 17:37:09 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "scene.h"

void	run_game(t_scene *scene)
{
	t_root	root;
	t_info	*info;
	t_line	line;

	root = init_root(scene);
	init_mlx(&root);
	info = init_info(&root);
	if (!info)
		game_error_and_exit(&root, "Root initialization");
	root.info = info;
	root.raycast = ft_calloc(1, sizeof(t_raycast));
	if (!root.raycast)
		game_error_and_exit(&root, "Root initialization");
	ft_bzero(&line, sizeof(t_line));
	mlx_loop_hook(root.window, generate_view, (void *)&root);
	mlx_loop_hook(root.window, move_player, (void *)&root);
	mlx_loop(root.window);
	mlx_terminate(root.window);
	root.window = NULL;
	free_root(&root);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (argc != 2)
		user_error_and_exit("Not enough arguments");
	if (!is_cub_file(argv[1]))
		user_error_and_exit("Not a .cub file");
	scene = load_scene_from_file(argv[1]);
	if (LOG)
		print_scene(&scene);
	run_game(&scene);
	scene_clear(&scene);
	return (EXIT_SUCCESS);
}
