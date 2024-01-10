/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:55:24 by bschaafs          #+#    #+#             */
/*   Updated: 2024/01/06 17:20:05 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(-ROT_SPEED) - info->dir_y * sin(-ROT_SPEED);
	info->dir_y = old_dir_x * sin(-ROT_SPEED) + info->dir_y * cos(-ROT_SPEED);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(-ROT_SPEED) \
	- info->plane_y * sin(-ROT_SPEED);
	info->plane_y = old_plane_x * sin(-ROT_SPEED) \
	+ info->plane_y * cos(-ROT_SPEED);
}

void	turn_right(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(ROT_SPEED) - info->dir_y * sin(ROT_SPEED);
	info->dir_y = old_dir_x * sin(ROT_SPEED) + info->dir_y * cos(ROT_SPEED);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(ROT_SPEED) \
	- info->plane_y * sin(ROT_SPEED);
	info->plane_y = old_plane_x * sin(ROT_SPEED) \
	+ info->plane_y * cos(ROT_SPEED);
}
