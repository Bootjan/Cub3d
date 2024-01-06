/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:10:19 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 17:33:20 by bootjan          ###   ########.fr       */
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

# define PATH1 "texture/kchrosci.png"
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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_info;

typedef struct s_raycast
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	uint8_t	side;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
}	t_raycast;

typedef struct s_line
{
	int		x;
	int		y0;
	int		y1;
	int		tex_x;
	int		tex_y;
	int		line_height;
	double	step;
	double	wall_x;
	double	tex_pos;
}	t_line;

typedef struct s_root
{
	int			*no_texture;
	int			*ea_texture;
	int			*so_texture;
	int			*we_texture;
	char		*no_path;
	char		*ea_path;
	char		*so_path;
	char		*we_path;

	uint8_t		rgb_ceil[3];
	uint8_t		rgb_floor[3];
	int			color_ceil;
	int			color_floor;

	char		**map;
	u_int8_t	pos_x;
	u_int8_t	pos_y;
	char		dir;

	mlx_t		*window;
	mlx_image_t	*image;

	t_info		*info;
	t_raycast	*raycast;
}	t_root;

// ### GENERATE VIEW ###########################################################
void	generate_view(void *arg);
uint8_t	dda(t_raycast *raycast, char **map);

// ### INITIALIZE ##############################################################
t_info	*init_info(t_root *root);
t_root	*init_mlx(t_root *root);

// ### UTILS ###################################################################
bool	valid_move(char **map, t_info *info, double y_plus, double x_plus);
double	ft_abs_double(double x);
void	free_root(t_root **root);
int		compute_color_rgb(uint8_t rgb[3]);
int		compute_color(int r, int g, int b, int a);

// ### MOVE PLAYER #############################################################
void	move_player(void *arg);
void	turn_left(t_info *info);
void	turn_right(t_info *info);

// ### DRAW LINE ###############################################################
void	init_line(t_line *line, t_raycast *raycast, t_info *info, int x);
void	draw_line(t_root *root, t_line *line, uint8_t side);

// ### ERROR HANDLING ##########################################################
t_root	*error_mlx(t_root **root);

#endif