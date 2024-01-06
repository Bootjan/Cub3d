/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:57:25 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 16:48:11 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_root(t_root **root)
{
	if ((*root)->info)
		free((*root)->info);
	(*root)->info = NULL;
	if ((*root)->raycast)
		free((*root)->raycast);
	(*root)->raycast = NULL;
	ft_free_2d_array((void ***)&((*root)->map));
	free(*root);
	*root = NULL;
}

int	compute_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	compute_color_rgb(uint8_t rgb[3])
{
	return (compute_color(rgb[0], rgb[1], rgb[2], 255));
}

double	ft_abs_double(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

bool	valid_move(char **map, t_info *info, double y_plus, double x_plus)
{
	return (map[(int)(info->pos_y + y_plus)] \
	[(int)(info->pos_x + x_plus)] != '1');
}
