/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:15 by bschaafs          #+#    #+#             */
/*   Updated: 2024/01/06 17:01:03 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_y_ymax(t_line *line, int *y, int *ymax)
{
	if (line->y0 < line->y1)
	{
		*y = line->y0;
		*ymax = line->y1;
	}
	else
	{
		*y = line->y1;
		*ymax = line->y0;
	}
}

static void	paint_line(t_root *root, t_line *line, int color)
{
	int	y;
	int	ymax;

	set_y_ymax(line, &y, &ymax);
	if (y >= 0)
		while (y < ymax && y < WINDOW_HEIGHT)
			mlx_put_pixel(root->image, line->x, y++, color);
}

static void	paint_texture(t_root *root, t_line *line, int *texture)
{
	int	y;
	int	ymax;

	set_y_ymax(line, &y, &ymax);
	while (y < ymax)
	{
		line->tex_y = (int)line->tex_pos & (TEX_SIZE - 1);
		line->tex_pos += line->step;
		mlx_put_pixel(root->image, line->x, y++, \
		texture[line->tex_y * TEX_SIZE + line->tex_x]);
	}
}

static void	draw_texture(t_root *root, t_line *line, uint8_t side)
{
	if (side == EAST)
		paint_texture(root, line, root->ea_texture);
	else if (side == NORTH)
		paint_texture(root, line, root->no_texture);
	else if (side == SOUTH)
		paint_texture(root, line, root->so_texture);
	else if (side == WEST)
		paint_texture(root, line, root->we_texture);
}

void	draw_line(t_root *root, t_line *line, uint8_t side)
{
	int	temp;

	draw_texture(root, line, side);
	temp = line->y1;
	line->y1 = line->y0;
	line->y0 = 0;
	paint_line(root, line, root->color_ceil);
	line->y0 = temp;
	line->y1 = WINDOW_HEIGHT;
	paint_line(root, line, root->color_floor);
}
