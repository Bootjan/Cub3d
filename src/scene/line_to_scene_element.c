/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_scene_element.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:12 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:25:13 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "scene.h"
#include <stdbool.h>
#include <stdio.h>

static char	**allocate_identifier_value_pair(char *line)
{
	char	**identifier_value;

	identifier_value = ft_split(line, " ");
	if (!identifier_value)
		system_error_and_exit("ft_split in string_to_scene");
	if (!identifier_value[0] || !identifier_value[1])
		user_error_and_exit("Not enough values in one of the settings");
	if (identifier_value[2])
		user_error_and_exit("Too many values in one of the settings");
	return (identifier_value);
}

bool	line_to_scene_element(t_scene *scene, char *line)
{
	char	**identifier_value;
	bool	element_found;

	element_found = true;
	identifier_value = allocate_identifier_value_pair(line);
	if (ft_strncmp(identifier_value[0], "NO", 3) == 0)
		set_scene_path(&scene->no_path, identifier_value[1]);
	else if (ft_strncmp(identifier_value[0], "EA", 3) == 0)
		set_scene_path(&scene->ea_path, identifier_value[1]);
	else if (ft_strncmp(identifier_value[0], "SO", 3) == 0)
		set_scene_path(&scene->so_path, identifier_value[1]);
	else if (ft_strncmp(identifier_value[0], "WE", 3) == 0)
		set_scene_path(&scene->we_path, identifier_value[1]);
	else if (ft_strncmp(identifier_value[0], "F", 2) == 0)
		string_to_rgb(identifier_value[1], &scene->floor);
	else if (ft_strncmp(identifier_value[0], "C", 2) == 0)
		string_to_rgb(identifier_value[1], &scene->ceil);
	else
		element_found = false;
	ft_free_str_table(&identifier_value);
	return (element_found);
}
