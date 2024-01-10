/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:26:08 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:26:09 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "scene.h"

void	set_scene_path(char **path, char *value)
{
	if (*path)
		free(*path);
	*path = ft_strdup(value);
	if (!*path)
		system_error_and_exit("ft_strdup in set_scene_path");
}
