/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:26:31 by safoh             #+#    #+#             */
/*   Updated: 10/01/2024 16:40:12 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "rectangle.h"
#include "scene.h"

static char	**allocate_rows(size_t height)
{
	char	**rows;

	rows = NULL;
	rows = ft_calloc(height, sizeof(char *));
	if (!rows)
		system_error_and_exit("calloc in allocate_rows");
	return (rows);
}

static char	*create_column(size_t width)
{
	char	*column;

	column = ft_calloc(width, sizeof(char));
	if (!column)
		system_error_and_exit("calloc in create_square_map");
	return (column);
}

t_rectangle_dimension	create_rectangle_map(char ***map)
{
	size_t					i;
	t_rectangle_dimension	dim;
	char					**square_map;
	size_t					map_len;

	i = 0;
	square_map = NULL;
	map_len = 0;
	dim = get_rectangle_dimension(*map);
	square_map = allocate_rows(dim.height + 1);
	i = 0;
	while ((*map)[i])
	{
		map_len = ft_strlen((*map)[i]);
		square_map[i] = create_column(dim.width + 1);
		ft_strlcpy(square_map[i], (*map)[i], map_len + 1);
		if (map_len < dim.width)
			ft_memset(square_map[i] + map_len, ' ', dim.width - map_len);
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = square_map;
	return (dim);
}
