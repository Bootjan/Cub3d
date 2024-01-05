/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchrosci <kchrosci@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 05:47:23 by kchrosci      #+#    #+#                 */
/*   Updated: 2023/12/30 22:38:56 by kchrosci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "../mlx/mlx.h"

# define X_EVENT_KEY_PRESS	    2
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

# define WIDTH			1280
# define HEIGHT			960
# define TEXTURE_WIDTH	64
# define TEXTURE_HEIGHT	64

# define BUFFER_SIZE 	4096
# define OPEN_MAX 		10240

typedef struct s_parse
{
	char		*av_path;
	int			fd;
	int			*check_li;
	int			check_cnt;
	int			empty_flag;
	char		*first_line;
	char		**texture_image_paths;
}				t_parse;

typedef struct s_img
{
	void		*img;
	int			*data_addr;
	int			width;
	int			height;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		texture_i;
	int		height;
	int		tex_x;
	int		tex_y;
	int		color;
}				t_ray;

typedef struct s_info
{
	int			*f_rgb;
	int			*c_rgb;
	t_img		*imgs;
	t_img		img;
	int			*buf;

	char		ewsn;
	int			map_width;
	int			map_height;
	char		**map;

	t_ray		*ray;

	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rotate_speed;

	int			img_len;
	void		*mlx;
	void		*win;
}				t_info;

//main.c
void			perror_exit(char *opt);
int				mlx_destroy_exit(t_info *info);

// gnl_utils.c
size_t			gnl_strlen(const char *s);
size_t			gnl_strlcpy(char *dst, const char *src, size_t size);
size_t			gnl_strlcat(char *dst, const char *src, size_t size);
char			*gnl_strdup(const char *s);
char			*gnl_strjoin(char *s1, char *s2);

// gnl.c
int				get_next_line(int fd, char **line);

//utils.c
void			init_data(t_parse *parse, t_info *info);
void			free_parse(t_parse *parse);
void			free_info(t_info *info);
void			free_arr(char **arr);
void			init(t_info *info);

//element_check.c
int				check_cub(t_parse *parse, char *path);
int				check_element(t_parse *parse, t_info *info);

//map_check.c
int				check_arr_size(char *str, char c, int n);
int				texture_path_check(t_parse *parse, t_info *info);
int				check_map(t_parse *parse, t_info *info);

//map_check2.c
int				check_map2(t_parse *parse, t_info *info);

//move.c
int				key_press(int key, t_info *info);

//raycast.c
void			first_ray_init(t_info *info);
void			raycast(t_info *info);

//draw.c
void			draw_floor_ceil(t_info *info);
void			draw_vertical_line(t_info *info, int x);
void			draw_map(t_info *info);

#endif
