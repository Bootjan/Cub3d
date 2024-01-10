/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:23:52 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:23:54 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "rectangle.h"
# include "rgb.h"
# include <stdbool.h>
# include <stdlib.h>

# define DEFAULT_PATH_NO "texture/kchrosci.png"
# define DEFAULT_PATH_SO "texture/polish_flag.png"
# define DEFAULT_PATH_WE "texture/playboy.png"
# define DEFAULT_PATH_EA "texture/safoh.png"

# define DEFAULT_FLOOR "255,0,0"
# define DEFAULT_CEIL "0,255,0"

typedef struct s_scene
{
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	t_rgb				floor;
	t_rgb				ceil;
	char				**map;
}						t_scene;

void					scene_clear(t_scene *scene);
bool					line_to_scene_element(t_scene *scene, char *string);
void					string_to_scene(char *string, t_scene *scene);
size_t					set_scene_elements(char *string, t_scene *scene);
void					set_default_scene(t_scene *scene);
void					set_scene_path(char **path, char *value);
void					print_scene(t_scene *scene);
void					set_scene_map(const char *string, t_scene *scene,
							size_t line_start);
t_rectangle_dimension	create_rectangle_map(char ***map);
void					check_valid_map(const char *string);

#endif
