/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_col_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:20:22 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:20:24 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

size_t	max_col_len(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}
