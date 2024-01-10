/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/01 22:10:19 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/10 16:04:08 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "error.h"
# include "libft.h"
# include "scene.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef LOG
#  define LOG 0
# endif

# define BUFFER_SIZE 32

# define WINDOW_HEIGHT 960
# define WINDOW_WIDTH 1280

# define TEX_SIZE 64
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.06

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_info;

typedef struct s_raycast
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	uint8_t		side;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
}				t_raycast;

typedef struct s_line
{
	int			x;
	int			y0;
	int			y1;
	int			tex_x;
	int			tex_y;
	int			line_height;
	double		step;
	double		wall_x;
	double		tex_pos;
}				t_line;

typedef struct s_root
{
	int			no_texture[TEX_SIZE * TEX_SIZE];
	int			ea_texture[TEX_SIZE * TEX_SIZE];
	int			so_texture[TEX_SIZE * TEX_SIZE];
	int			we_texture[TEX_SIZE * TEX_SIZE];
	char		*no_path;
	char		*ea_path;
	char		*so_path;
	char		*we_path;

	uint32_t	rgb_ceil[3];
	uint32_t	rgb_floor[3];
	uint32_t	color_ceil;
	uint32_t	color_floor;

	char		**map;
	int			pos_x;
	int			pos_y;
	char		dir;

	mlx_t		*window;
	mlx_image_t	*image;

	t_info		*info;
	t_raycast	*raycast;
}				t_root;

// ### GENERATE VIEW ###########################################################
void			generate_view(void *arg);
uint8_t			dda(t_raycast *raycast, char **map);

// ### PARSE ###################################################################
size_t			file_to_list(int fd, t_list **list);
char			*list_to_string(t_list *lst, size_t size);
char			*chunk_file_to_string(int fd);
t_scene			load_scene_from_file(char *file_path);

// ### INITIALIZE ##############################################################
t_info			*init_info(t_root *root);
void			init_mlx(t_root *root);
t_root			init_root(t_scene *scene);

// ### UTILS ###################################################################
bool			valid_move(char **map, t_info *info, double y_plus,
					double x_plus);
double			ft_abs_double(double x);
void			free_root(t_root *root);
bool			is_cub_file(const char *filename);

// ### MOVE PLAYER #############################################################
void			move_player(void *arg);
void			turn_left(t_info *info);
void			turn_right(t_info *info);

// ### DRAW LINE ###############################################################
void			init_line(t_line *line, t_raycast *raycast, t_info *info,
					int x);
void			draw_line(t_root *root, t_line *line, uint8_t side);

// ### ERROR HANDLING ##########################################################
t_root			*error_mlx(t_root *root);
void			game_error_and_exit(t_root *root, const char *err_msg);

unsigned int	compute_color_rgb(uint32_t rgb[3]);
unsigned int	compute_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a);

#endif
