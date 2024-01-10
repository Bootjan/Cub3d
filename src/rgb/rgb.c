/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:09:03 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:09:04 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "rgb.h"

uint32_t	compute_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	compute_color_rgb(uint32_t rgb[3])
{
	return (compute_color(rgb[0], rgb[1], rgb[2], 255));
}

static void	values_to_rgb(int *values, t_rgb *rgb)
{
	if (values[0] < 0 || values[0] > 255 || values[1] < 0 || values[1] > 255
		|| values[2] < 0 || values[2] > 255)
		user_error_and_exit("RGB values out of range");
	rgb->r = (uint8_t)values[0];
	rgb->g = (uint8_t)values[1];
	rgb->b = (uint8_t)values[2];
}

static void	string_to_values(const char **string, int *values, int i)
{
	int	char_count;

	char_count = 0;
	while (**string >= '0' && **string <= '9')
	{
		if (char_count > 3)
			user_error_and_exit("RGB values out of range");
		values[i] = values[i] * 10 + (**string - '0');
		++*string;
		char_count++;
	}
}

void	string_to_rgb(const char *string, t_rgb *rgb)
{
	int	values[3];
	int	i;

	i = 0;
	ft_bzero(values, sizeof(values));
	while (*string != '\0' && i < 3)
	{
		string_to_values(&string, values, i);
		if (*string != '\0' && *string != ',' && *string != '\n')
			user_error_and_exit("Unexpected character in RGB values");
		if (*string == ',')
			++string;
		++i;
	}
	if (i != 3 && *string != '\0' && *string != '\n')
		user_error_and_exit("Format error in RGB values");
	values_to_rgb(values, rgb);
}
