/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene_from_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:26:43 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:26:43 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scene	load_scene_from_file(char *file_path)
{
	t_scene	scene;
	char	*string;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		system_error_and_exit("open in load_scene_from_file");
	string = chunk_file_to_string(fd);
	close(fd);
	ft_bzero(&scene, sizeof(t_scene));
	set_default_scene(&scene);
	string_to_scene(string, &scene);
	free(string);
	return (scene);
}
