/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:10:19 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 00:25:06 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "MLX42.h"
# include "MLX42_Int.h"

# define WINDOW_HEIGHT 960
# define WINDOW_WIDTH 1280

# define PATH "texture/kchrosci.png"
# define PATH2 "texture/polish_flag.png"
# define PATH3 "texture/playboy.png"
# define PATH4 "texture/safoh.png"

# define TEX_SIZE 512
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.03

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

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
	uint8_t	side;
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
	int		x;
	int		y0;
	int		y1;
	int		texX;
	int		texY;
	int		lineHeight;
	double	step;
	double	wallX;
	double	texPos;
}	t_line;

typedef struct s_root
{
	int			*noTexture;
	int			*eaTexture;
	int			*soTexture;
	int			*weTexture;
	uint8_t		rgb_ceil[3];
	uint8_t		rgb_floor[3];
	int			color_ceil;
	int			color_floor;
	mlx_t		*window;
	mlx_image_t	*image;
	int			imageIndex;
	t_info		*info;
	t_raycast	*raycast;
	char		**map;
}	t_root;

t_root	*compute_root(void);
void	look_for_wall(t_info *info, t_raycast *raycast, char **map);
int		compute_color(int r, int g, int b, int a);

// ### MOVE PLAYER #############################################################
void	move_player(void *arg);
void	turn_left(t_info *info);
void	turn_right(t_info *info);

// ### DRAW LINE ###############################################################
void	init_line(t_line *line, t_raycast *raycast, t_info *info, int x);
void	draw_line(t_root *root, t_line *line, uint8_t side);

#endif