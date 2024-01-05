/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turn_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 16:55:24 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/04 16:55:37 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = info->dirX;
	info->dirX = info->dirX * cos(-ROT_SPEED) - info->dirY * sin(-ROT_SPEED);
	info->dirY = oldDirX * sin(-ROT_SPEED) + info->dirY * cos(-ROT_SPEED);
	oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(-ROT_SPEED) - info->planeY * sin(-ROT_SPEED);
	info->planeY = oldPlaneX * sin(-ROT_SPEED) + info->planeY * cos(-ROT_SPEED);
}

void	turn_right(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = info->dirX;
	info->dirX = info->dirX * cos(ROT_SPEED) - info->dirY * sin(ROT_SPEED);
	info->dirY = oldDirX * sin(ROT_SPEED) + info->dirY * cos(ROT_SPEED);
	oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(ROT_SPEED) - info->planeY * sin(ROT_SPEED);
	info->planeY = oldPlaneX * sin(ROT_SPEED) + info->planeY * cos(ROT_SPEED);
}
