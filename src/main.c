/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:10:00 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 17:27:11 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


char	**load_map(void)
{
	int		fd = open("maps/default.cub", O_RDONLY);
	if (fd == -1)
		return (NULL);
	char	**map = ft_calloc(25, sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	for (int i = 0; i < 24; i++)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (ft_free_2d_array((void ***)&map), close(fd), NULL);
	}
	close(fd);
	return (map);
}

t_root	*init_root(void)
{
	t_root	*root;
	
	root = ft_calloc(1, sizeof(t_root));
	if (!root)
		return (NULL);
	root->map = load_map();
	if (!root->map)
		return (free(root), NULL);
	root->rgb_ceil[0] = 204;
	root->rgb_ceil[1] = 153;
	root->rgb_ceil[2] = 255;
	root->rgb_floor[0] = 52;
	root->rgb_floor[1] = 154;
	root->rgb_floor[2] = 237;
	root->no_path = PATH1;
	root->ea_path = PATH2;
	root->so_path = PATH3;
	root->we_path = PATH4;
	root->pos_x = 12;
	root->pos_y = 12;
	root->dir = 'E';
	return (root);
}

int	main(void) //int argc, const char **argv)
{
	t_root	*root = init_root();
	if (!root)
		return (1);
	root = init_mlx(root);
	if (!root)
		return (1);
	t_info	*info = init_info(root);
	if (!info)
		return (free_root(&root), 1);
	root->info = info;
	t_raycast	*raycast = ft_calloc(1, sizeof(t_raycast));
	if (!raycast)
		return (free_root(&root), 1);
	root->raycast = raycast;
	
	t_line		line;
	ft_bzero(&line, sizeof(t_line));
	mlx_loop_hook(root->window, generate_view, (void *)root);
	mlx_loop_hook(root->window, move_player, (void *)root);
	mlx_loop(root->window);
	mlx_terminate(root->window);
	free_root(&root);
	return (0);
}
