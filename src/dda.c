/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:18:49 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/05 23:42:31 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_abs_double(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double	computeSideDistX(t_raycast *raycast, t_info *info)
{
	if (raycast->rayDirX < 0)
	{
		raycast->stepX = -1;
		return ((info->posX - raycast->mapX) * raycast->deltaDistX);
	}
	raycast->stepX = 1;
	return ((raycast->mapX + 1.0 - info->posX) * raycast->deltaDistX);
}

double	computeSideDistY(t_raycast *raycast, t_info *info)
{
	if (raycast->rayDirY < 0)
	{
		raycast->stepY = -1;
		return ((info->posY - raycast->mapY) * raycast->deltaDistY);
	}
	raycast->stepY = 1;
	return ((raycast->mapY + 1.0 - info->posY) * raycast->deltaDistY);
}

int	update_x_values(t_raycast *raycast)
{
	raycast->sideDistX += raycast->deltaDistX;
	raycast->mapX += raycast->stepX;
	if (raycast->stepX < 0.0)
		return (EAST);
	else
		return (WEST);
}

int		update_y_values(t_raycast *raycast)
{
	raycast->sideDistY += raycast->deltaDistY;
	raycast->mapY += raycast->stepY;
	if (raycast->stepY < 0.0)
		return (NORTH);
	else
		return (SOUTH);
}

uint8_t	dda(t_raycast *raycast, char **map)
{
	uint8_t	side;

	while (true)
	{
		if (raycast->sideDistX < raycast->sideDistY)
			side = update_x_values(raycast);
		else
			side = update_y_values(raycast);
		if (map[raycast->mapY][raycast->mapX] == '1')
			break ;
	}
	return (side);
}

void	look_for_wall(t_info *info, t_raycast *raycast, char **map)
{
	raycast->rayDirX = info->dirX + info->planeX * raycast->cameraX;
	raycast->rayDirY = info->dirY + info->planeY * raycast->cameraX;
	raycast->mapX = (int)info->posX;
	raycast->mapY = (int)info->posY;
	raycast->deltaDistX = ft_abs_double(1 / raycast->rayDirX);
	raycast->deltaDistY = ft_abs_double(1 / raycast->rayDirY);
	raycast->sideDistX = computeSideDistX(raycast, info);
	raycast->sideDistY = computeSideDistY(raycast, info);
	raycast->side = dda(raycast, map);
	if (raycast->side <= SOUTH)
		raycast->perpWallDist = raycast->sideDistY - raycast->deltaDistY;
	else
		raycast->perpWallDist = raycast->sideDistX - raycast->deltaDistX;
}