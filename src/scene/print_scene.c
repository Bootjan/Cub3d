/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:23 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:25:24 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdio.h>

void	print_scene(t_scene *scene)
{
	size_t	i;

	i = 0;
	printf("no_path: %s\n", scene->no_path);
	printf("ea_path: %s\n", scene->ea_path);
	printf("so_path: %s\n", scene->so_path);
	printf("we_path: %s\n", scene->we_path);
	printf("floor: r%d, g%d, b%d\n", scene->floor.r, scene->floor.g,
		scene->floor.b);
	printf("ceil: r%d, g%d, b%d\n", scene->ceil.r, scene->ceil.g,
		scene->ceil.b);
	printf("map:\n");
	if (!scene->map)
		return ;
	while (scene->map[i])
	{
		printf("%s\n", scene->map[i]);
		i++;
	}
}
