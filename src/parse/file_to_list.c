/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:38:35 by safoh             #+#    #+#             */
/*   Updated: 10/01/2024 15:50:28 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_buffer_to_list(char *buffer, t_list **list)
{
	t_list	*new;
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(buffer);
	if (!tmp)
		system_error_and_exit("ft_strdup in add_buffer_to_list");
	new = ft_lstnew(tmp);
	if (!new)
		system_error_and_exit("ft_lstnew in add_buffer_to_list");
	ft_lstadd_back(list, new);
}

size_t	file_to_list(int fd, t_list **list)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	total_read;
	ssize_t	read_return;

	total_read = 0;
	while (1)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
			system_error_and_exit("get_next_line");
		if (read_return == 0)
			break ;
		total_read += read_return ;
		buffer[read_return] = '\0';
		add_buffer_to_list(buffer, list);
	}
	return (total_read);
}
