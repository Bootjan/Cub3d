/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:41:05 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 17:41:06 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str_table(char ***str_table)
{
	int	i;

	if (!str_table || !*str_table)
		return ;
	i = 0;
	while ((*str_table)[i])
		free((*str_table)[i++]);
	free(*str_table);
	*str_table = NULL;
}
