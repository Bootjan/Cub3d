/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/01 22:10:00 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/04 19:01:05 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d_array(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
		free((*arr)[i++]);
	free(*arr);
	*arr = NULL;
}

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
			return (free_2d_array(&map), close(fd), NULL);
	}
	close(fd);
	return (map);
}

t_info	*init_info(void)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (NULL);
	info->posX = 12;
	info->posY = 12;
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0.0;
	info->planeY = 0.0;
	if (info->dirY > 0)
		info->planeX = -0.66;
	else if (info->dirY < 0)
		info->planeX = 0.66;
	else if (info->dirX > 0)
		info->planeY = 0.66;
	else if (info->dirX < 0)
		info->planeY = -0.66;
	return (info);
}


void	generate_view(void *arg)
{
	t_root	*root;
	t_line	line;

	root = (t_root *)arg;
	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
		root->raycast->cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
		look_for_wall(root->info, root->raycast, root->map);
		init_line(&line, root->raycast, root->info, x);
		draw_line(root, &line, root->raycast->side);
	}
}

int	main(void) //int argc, const char **argv)
{
	t_info	*info = init_info();
	if (!info)
		return (1);
	char	**map = load_map();
	if (!map)
		return (free(info), 1);
	t_root *root = compute_root();
	if (!root)
		return (free(info), free_2d_array(&map), 1);
	
	t_raycast	*raycast;
	raycast = ft_calloc(1, sizeof(t_raycast));
	t_line		line;
	ft_bzero(&line, sizeof(t_line));
	root->info = info;
	root->raycast = raycast;
	root->map = map;
	mlx_loop_hook(root->window, generate_view, (void *)root);
	mlx_loop_hook(root->window, move_player, (void *)root);
	mlx_loop(root->window);
	mlx_terminate(root->window);
	free(root->info);
	free(raycast);
	free(root);
	return (free_2d_array(&map), 0);
}
