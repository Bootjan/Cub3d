/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_file_into_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:37:55 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 15:37:58 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*chunk_file_to_string(int fd)
{
	t_list	*chunks;
	char	*string;
	size_t	size;

	chunks = NULL;
	string = NULL;
	size = 0;
	size = file_to_list(fd, &chunks);
	string = list_to_string(chunks, size);
	ft_lstclear(&chunks, free);
	return (string);
}
