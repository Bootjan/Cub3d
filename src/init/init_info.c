/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_info.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 15:50:21 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/10 13:45:36 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_direction(t_info *info, char direction)
{
	if (direction == 'N')
		info->dir_y -= 1;
	else if (direction == 'S')
		info->dir_y += 1;
	else if (direction == 'E')
		info->dir_x -= 1;
	else if (direction == 'W')
		info->dir_x += 1;
}

static void	set_plane(t_info *info)
{
	info->plane_x = 0.0;
	info->plane_y = 0.0;
	if (info->dir_y > 0)
		info->plane_x = -0.66;
	else if (info->dir_y < 0)
		info->plane_x = 0.66;
	else if (info->dir_x > 0)
		info->plane_y = 0.66;
	else if (info->dir_x < 0)
		info->plane_y = -0.66;
}

t_info	*init_info(t_root *root)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (NULL);
	info->pos_x = root->pos_x + 0.5;
	info->pos_y = root->pos_y + 0.5;
	set_direction(info, root->dir);
	set_plane(info);
	return (info);
}
