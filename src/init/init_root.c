/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_root.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 11:48:48 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/10 17:38:38 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_player(char c)
{
	return (c == 'E' || c == 'W' || c == 'S' || c == 'N');
}

static void	set_player(t_root *root, int x, int y)
{
	root->pos_x = x;
	root->pos_y = y;
	root->dir = root->map[y][x];
}

static int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

static void	find_player(t_root *root)
{
	int	x;
	int	y;
	int	map_width;
	int	map_height;

	y = 0;
	map_height = arr_len(root->map);
	map_width = ft_strlen(root->map[0]);
	while (y < map_height)
	{
		x = 0;
		while (x < map_width)
		{
			if (is_player(root->map[y][x]))
			{
				set_player(root, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

t_root	init_root(t_scene *scene)
{
	t_root	root;

	ft_bzero(&root, sizeof(t_root));
	root.map = scene->map;
	root.rgb_ceil[0] = scene->ceil.r;
	root.rgb_ceil[1] = scene->ceil.g;
	root.rgb_ceil[2] = scene->ceil.b;
	root.rgb_floor[0] = scene->floor.r;
	root.rgb_floor[1] = scene->floor.g;
	root.rgb_floor[2] = scene->floor.b;
	root.no_path = scene->no_path;
	root.ea_path = scene->ea_path;
	root.so_path = scene->so_path;
	root.we_path = scene->we_path;
	find_player(&root);
	return (root);
}
