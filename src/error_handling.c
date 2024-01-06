/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:32:43 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 17:32:59 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*error_mlx(t_root **root)
{
	mlx_terminate((*root)->window);
	free_root(root);
	printf("Error\n");
	return (NULL);
}
