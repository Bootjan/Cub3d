/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 16:56:15 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/04 16:57:51 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	paint_line(t_root *root, t_line *line, int color)
{
	int	y;
	int	yMax;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		yMax = line->y1;
	}
	else
	{
		y = line->y1;
		yMax = line->y0;
	}
	if (y >= 0) // needed?
	{
		while (y < yMax && y < WINDOW_HEIGHT)
		{
			mlx_put_pixel(root->image, line->x, y, color);
			y++;
		}
	}
}

void	draw_line(t_root *root, t_line *line, int side)
{
	int	temp;

	if (side == 1)
		paint_line(root, line, WALL);
	else
		paint_line(root, line, WALL / 2);
	temp = line->y1;
	line->y1 = line->y0;
	line->y0 = 0;
	paint_line(root, line, CEILING);
	line->y0 = temp;
	line->y1 = WINDOW_HEIGHT;
	paint_line(root, line, FLOOR);
}

void	init_line(t_line *line, t_raycast *raycast, int x)
{
	line->lineHeight = (int)(WINDOW_HEIGHT / raycast->perpWallDist);
	line->y0 = WINDOW_HEIGHT / 2 - line->lineHeight / 2;
	if (line->y0 < 0)
		line->y0 = 0;
	line->y1 = WINDOW_HEIGHT / 2 + line->lineHeight / 2;
	if (line->y1 >= WINDOW_HEIGHT)
		line->y1 = WINDOW_HEIGHT - 1;
	line->x = x;
}
