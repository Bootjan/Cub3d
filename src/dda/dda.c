/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:18:49 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 16:18:02 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	update_x_values(t_raycast *raycast)
{
	raycast->side_dist_x += raycast->delta_dist_x;
	raycast->map_x += raycast->step_x;
	if (raycast->step_x < 0.0)
		return (EAST);
	else
		return (WEST);
}

static int	update_y_values(t_raycast *raycast)
{
	raycast->side_dist_y += raycast->delta_dist_y;
	raycast->map_y += raycast->step_y;
	if (raycast->step_y < 0.0)
		return (NORTH);
	else
		return (SOUTH);
}

uint8_t	dda(t_raycast *raycast, char **map)
{
	uint8_t	side;

	while (true)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
			side = update_x_values(raycast);
		else
			side = update_y_values(raycast);
		if (map[raycast->map_y][raycast->map_x] == '1')
			break ;
	}
	return (side);
}
