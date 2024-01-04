/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:10:00 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/04 02:07:24 by bootjan          ###   ########.fr       */
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

t_info	*init_info(void)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (NULL);
	info->posX = 2;
	info->posY = 1;
	info->dirX = 0;
	info->dirY = 1;
	info->planeX = 0;
	info->planeY = 0.66;
	return (info);
}

void	paint_line(int y, int yMax)
{
	// int	y;
	// int	yMax;

	// if (line->y0 < line->y1)
	// {
	// 	y = line->y0;
	// 	yMax = line->y1;
	// }
	// else
	// {
	// 	y = line->y1;
	// 	yMax = line->y0;
	// }
	if (y >= 0) // needed?
	{
		while (y < yMax)
		{
			mlx_put_pixel(rgbCode, line->x, y, rgbCode);
			y++;
		}
	}
}

// void	draw_line(t_info *info, t_raycast *raycast)
// {
// 	if (something)
// 		paint_texture_line();
// 	line->y0 = 0;
// 	line->y1 = ray->drawStart;
// 	paint_line(root, line, rgbCode);
// 	line->y0 = WINDOW_HEIGHT;
// 	line->y1 = ray->drawEnd;
// 	paint_line(root, line, rgbCode);
// }

void	draw_line(t_line line)
{
	paint_line()
}

void	init_line(t_line *line, t_raycast raycast)
{
	line->lineHeight = (int)(WINDOW_HEIGHT / raycast.perpWallDist);
	line->y0 = WINDOW_HEIGHT / 2 - line->lineHeight / 2;
	if (line->y0 < 0)
		line->y0 = 0;
	line->y1 = WINDOW_HEIGHT / 2 + line->lineHeight / 2;
	if (line->y1 >= WINDOW_HEIGHT)
		line->y1 = WINDOW_HEIGHT - 1;
}

int	main(int argc, const char **argv)
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
	
	double		cameraX;
	double		perpWallDist;
	double		wallX;
	// double		scale;
	t_raycast	raycast;

	for (int i = 0; i < 60; i++)
	{
		raycast.cameraX = 2 * i / double(60) - 1;
		look_for_wall(info, &raycast, map);
		init_line(&line, raycast);
		draw_line(info, raycast);
		// if (raycast.side == WEST || raycast.side == EAST)
		// 	wallX = info->posY + raycast.perpWallDist * raycast.rayDirY;
		// else
		// 	wallX = info->posX + raycast.perpWallDist * raycast.rayDirX;
		// wallX -= floor(wallX); // find out what floor does
		// scale = line->y - (WINDOW_HEIGHT) / 2 + raycast->lineHeigt
		// paint_it()
	}
	open_window();
	place_images();
	return (free_2d_array(&map), 0);
}
