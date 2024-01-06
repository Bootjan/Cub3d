/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:31:52 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 16:56:25 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_y01(t_line *line)
{
	line->y0 = WINDOW_HEIGHT / 2 - line->line_height / 2;
	if (line->y0 < 0)
		line->y0 = 0;
	line->y1 = WINDOW_HEIGHT / 2 + line->line_height / 2;
	if (line->y1 >= WINDOW_HEIGHT)
		line->y1 = WINDOW_HEIGHT - 1;
}

static void	set_wall_x(t_line *line, t_info *info, t_raycast *raycast)
{
	if (raycast->side <= SOUTH)
		line->wall_x = info->pos_x + \
		raycast->perp_wall_dist * raycast->ray_dir_x;
	else
		line->wall_x = info->pos_y + \
		raycast->perp_wall_dist * raycast->ray_dir_y;
	line->wall_x -= floor(line->wall_x);
}

static void	set_tex_x(t_line *line, t_raycast *raycast)
{
	line->tex_x = (int)(line->wall_x * (double)TEX_SIZE);
	if (raycast->side <= SOUTH && raycast->ray_dir_y > 0)
		line->tex_x = TEX_SIZE - line->tex_x - 1;
	if (raycast->side > SOUTH && raycast->ray_dir_x < 0)
		line->tex_x = TEX_SIZE - line->tex_x - 1;
}

void	init_line(t_line *line, t_raycast *raycast, t_info *info, int x)
{
	line->line_height = (int)(WINDOW_HEIGHT / raycast->perp_wall_dist);
	set_y01(line);
	line->x = x;
	set_wall_x(line, info, raycast);
	set_tex_x(line, raycast);
	line->step = 1.0 * TEX_SIZE / line->line_height;
	line->tex_pos = (line->y0 + line->line_height / 2 - WINDOW_HEIGHT / 2) \
	* line->step;
}
