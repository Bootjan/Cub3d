/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rectangle_dimension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:18:47 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:19:10 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rectangle.h"
#include "utils.h"

t_rectangle_dimension	get_rectangle_dimension(char **map)
{
	t_rectangle_dimension	dimension;

	dimension.width = max_col_len(map);
	dimension.height = row_len(map);
	return (dimension);
}
