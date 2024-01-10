/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:48 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:25:50 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "scene.h"

void	set_default_scene(t_scene *scene)
{
	set_scene_path(&scene->no_path, DEFAULT_PATH_NO);
	set_scene_path(&scene->so_path, DEFAULT_PATH_SO);
	set_scene_path(&scene->we_path, DEFAULT_PATH_WE);
	set_scene_path(&scene->ea_path, DEFAULT_PATH_EA);
	string_to_rgb(DEFAULT_FLOOR, &scene->floor);
	string_to_rgb(DEFAULT_CEIL, &scene->ceil);
}
