/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:38:49 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 15:38:51 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*list_to_string(t_list *lst, size_t size)
{
	char	*chunk;
	char	*string;

	chunk = NULL;
	string = NULL;
	string = ft_calloc(size + 1, sizeof(char));
	if (!string)
		system_error_and_exit("calloc in list_to_string");
	while (lst)
	{
		chunk = lst->content;
		ft_strlcat(string, chunk, size);
		lst = lst->next;
	}
	return (string);
}
