/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 00:18:49 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/04 17:37:57 by bschaafs      ########   odam.nl         */
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

int	dda(t_raycast *raycast, char **map)
{
	int	side;

	while (true)
	{
		if (raycast->sideDistX < raycast->sideDistY)
		{
			raycast->sideDistX += raycast->deltaDistX;
			raycast->mapX += raycast->stepX;
			side = 0;
		}
		else
		{
			raycast->sideDistY += raycast->deltaDistY;
			raycast->mapY += raycast->stepY;
			side = 1;
		}
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
	if (raycast->rayDirX == 0)
		raycast->deltaDistX = 1e30;
	else	
		raycast->deltaDistX = ft_abs_double(1 / raycast->rayDirX);
	if (raycast->rayDirY == 0)
		raycast->deltaDistY = 1e30;
	else	
		raycast->deltaDistY = ft_abs_double(1 / raycast->rayDirY);
	raycast->sideDistX = computeSideDistX(raycast, info);
	raycast->sideDistY = computeSideDistY(raycast, info);
	raycast->side = dda(raycast, map);
	if (raycast->side == 0)
		raycast->perpWallDist = raycast->sideDistX - raycast->deltaDistX;
	else
		raycast->perpWallDist = raycast->sideDistY - raycast->deltaDistY;
}
