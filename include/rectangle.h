/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:23:43 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:23:44 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_H
# define RECTANGLE_H

# include <stddef.h>

typedef struct s_rectangle_dimension
{
	size_t				height;
	size_t				width;
}						t_rectangle_dimension;

t_rectangle_dimension	get_rectangle_dimension(char **map);

#endif
