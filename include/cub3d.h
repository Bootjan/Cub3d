/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:10:19 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/04 02:10:46 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "MLX42.h"
# include "MLX42_Int.h"

# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 500
# define IMAGE_SIZE 100

# define PATH "textures/kchrosci.jpeg"

typedef struct s_root
{
	mlx_t		*window;
	mlx_image_t	*image;
	// mlx_image_t	*no_image;
	// mlx_image_t	*ea_image;
	// mlx_image_t	*so_image;
	// mlx_image_t	*we_image;
}	t_root;

typedef struct s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_info;

typedef struct s_raycast
{
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		side;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
}	t_raycast;

typedef struct s_line
{
	int	x;
	int	y;
	int	y0;
	int	y1;
	int	texX;
	int	texY;
	int	lineHeight;
}	t_line;

#endif