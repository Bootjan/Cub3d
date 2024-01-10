/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:17:15 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 17:26:07 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	compute_side_dist_x(t_raycast *raycast, t_info *info)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		return ((info->pos_x - raycast->map_x) * raycast->delta_dist_x);
	}
	raycast->step_x = 1;
	return ((raycast->map_x + 1.0 - info->pos_x) * raycast->delta_dist_x);
}

static double	compute_side_dist_y(t_raycast *raycast, t_info *info)
{
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		return ((info->pos_y - raycast->map_y) * raycast->delta_dist_y);
	}
	raycast->step_y = 1;
	return ((raycast->map_y + 1.0 - info->pos_y) * raycast->delta_dist_y);
}

static void	look_for_wall(t_info *info, t_raycast *raycast, char **map)
{
	raycast->ray_dir_x = info->dir_x + info->plane_x * raycast->camera_x;
	raycast->ray_dir_y = info->dir_y + info->plane_y * raycast->camera_x;
	raycast->map_x = (int)info->pos_x;
	raycast->map_y = (int)info->pos_y;
	raycast->delta_dist_x = ft_abs_double(1 / raycast->ray_dir_x);
	raycast->delta_dist_y = ft_abs_double(1 / raycast->ray_dir_y);
	raycast->side_dist_x = compute_side_dist_x(raycast, info);
	raycast->side_dist_y = compute_side_dist_y(raycast, info);
	raycast->side = dda(raycast, map);
	if (raycast->side <= SOUTH)
		raycast->perp_wall_dist = raycast->side_dist_y - raycast->delta_dist_y;
	else
		raycast->perp_wall_dist = raycast->side_dist_x - raycast->delta_dist_x;
}

void	generate_view(void *arg)
{
	int		x;
	t_root	*root;
	t_line	line;

	x = 0;
	root = (t_root *)arg;
	while (x < WINDOW_WIDTH)
	{
		root->raycast->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		look_for_wall(root->info, root->raycast, root->map);
		init_line(&line, root->raycast, root->info, x++);
		draw_line(root, &line, root->raycast->side);
	}
}
