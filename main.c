/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:10:00 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/01 23:00:58 by bootjan          ###   ########.fr       */
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
	char	**map = ft_calloc(7, sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	for (int i = 0; i < 6; i++)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (free_2d_array(&map), close(fd), NULL);
	}
	close(fd);
	return (map);
}

mlx_t	*init_window_images(t_images **images, char **map, t_mapinfo map_info)
{
	mlx_t	*window;

	window = mlx_init(MAP_WIDTH, MAP_HEIGHT, "CUB3D...", true);
	if (!window)
	{
		printf("Error\n"); // Better error messages
		return (NULL);
	}
	*images = load_images(window);
	if (!*images)
	{
		mlx_terminate(window);
		printf("Error\n"); // Better error messages
		return (NULL);
	}
	*coins_info = put_images_to_window(window, *images, map, map_info);
	if (!*coins_info)
	{
		mlx_terminate(window);
		free(*images);
		printf("Error\n"); // Better error messages
		return (NULL);
	}
	return (window);
}

int	main(int argc, const char **argv)
{
	char	**map = load_map();
	if (!map)
		return (1);
	open_window();
	place_images();
	return (free_2d_array(&map), 0);
}
