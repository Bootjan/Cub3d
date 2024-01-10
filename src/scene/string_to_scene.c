/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:26:17 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:26:19 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	string_to_scene(char *string, t_scene *scene)
{
	size_t	line_start;

	line_start = 0;
	line_start = set_scene_elements(string, scene);
	set_scene_map(string, scene, line_start);
}
