/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:23:19 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:23:22 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

# include <stdint.h>

typedef struct s_rgb
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}				t_rgb;

void			string_to_rgb(const char *str, t_rgb *rgb);

#endif
