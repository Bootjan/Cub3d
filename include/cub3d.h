/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/01 22:10:19 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/04 16:58:21 by bschaafs      ########   odam.nl         */
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
# define IMAGE_SIZE 100

# define PATH "textures/kchrosci.jpeg"

# define CEILING 0
# define WALL 16731469
# define FLOOR 16777215

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.03

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

typedef struct s_root
{
	mlx_t		*window;
	mlx_image_t	*image;
	int			imageIndex;
	t_info		*info;
	t_raycast	*raycast;
	char		**map;
}	t_root;

t_root	*compute_root(void);
void	look_for_wall(t_info *info, t_raycast *raycast, char **map);

// ### MOVE PLAYER #############################################################
void	move_player(void *arg);
void	turn_left(t_info *info);
void	turn_right(t_info *info);

// ### DRAW LINE ###############################################################
void	init_line(t_line *line, t_raycast *raycast, int x);
void	draw_line(t_root *root, t_line *line, int side);

#endif