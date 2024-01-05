/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:15 by bschaafs          #+#    #+#             */
/*   Updated: 2024/01/05 01:25:05 by bootjan          ###   ########.fr       */
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
		while (y < yMax && y < WINDOW_HEIGHT)
			mlx_put_pixel(root->image, line->x, y++, color);
}

static void	paint_texture(t_root *root, t_line *line, int *texture)
{
	int	y;
	int	yMax;

	// if (line->y0 < line->y1)
	// {
	y = line->y0;
	yMax = line->y1;
	// }
	// else
	// {
	// 	y = line->y1;
	// 	yMax = line->y0;
	// }
	while (y < yMax)
	{
		line->texY = (int)line->texPos & (TEX_WIDTH - 1);
		line->texPos += line->step;
		mlx_put_pixel(root->image, line->x, y, texture[line->texY * TEX_WIDTH + line->texX]);
		y++;
	}
}

void	draw_line(t_root *root, t_line *line, int side)
{
	int	temp;
	int	color;

	if (side == EAST) // east and west
		paint_texture(root, line, root->eaTexture);
	else if (side == NORTH)// north and south
		paint_texture(root, line, root->noTexture);
	else if (side == SOUTH)
		paint_texture(root, line, root->soTexture);
	else if (side == WEST)
		paint_texture(root, line, root->weTexture);
	temp = line->y1;
	line->y1 = line->y0;
	line->y0 = 0;
	color = compute_color(204, 153, 255, 255);
	paint_line(root, line, color);
	line->y0 = temp;
	line->y1 = WINDOW_HEIGHT;
	paint_line(root, line, FLOOR);
}

void	init_line(t_line *line, t_raycast *raycast, t_info *info, int x)
{
	line->lineHeight = (int)(WINDOW_HEIGHT / raycast->perpWallDist);
	line->y0 = WINDOW_HEIGHT / 2 - line->lineHeight / 2;
	if (line->y0 < 0)
		line->y0 = 0;
	line->y1 = WINDOW_HEIGHT / 2 + line->lineHeight / 2;
	if (line->y1 >= WINDOW_HEIGHT)
		line->y1 = WINDOW_HEIGHT - 1;
	line->x = x;
	if (raycast->side <= SOUTH)
		line->wallX = info->posX + raycast->perpWallDist * raycast->rayDirX;
	else
		line->wallX = info->posY + raycast->perpWallDist * raycast->rayDirY;
	line->wallX -= floor(line->wallX);
	line->texX = (int)(line->wallX * (double)TEX_WIDTH);
	if (raycast->side <= SOUTH && raycast->rayDirY > 0)
		line->texX = TEX_WIDTH - line->texX - 1;
	if (raycast->side > SOUTH && raycast->rayDirX < 0)
		line->texX = TEX_WIDTH - line->texX - 1;
	line->step = raycast->perpWallDist * raycast->perpWallDist * 0.02; //2.4 * TEX_WIDTH / line->lineHeight;
	if (line->step == 0)
		line->step = 1;
	line->texPos = (line->y0 + line->lineHeight / 2 - WINDOW_HEIGHT / 2) * line->step;
}
