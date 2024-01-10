/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_error_and_exit.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 13:46:38 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/10 18:05:03 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_root(t_root *root)
{
	if (root->info)
		free(root->info);
	root->info = NULL;
	if (root->raycast)
		free(root->raycast);
	root->raycast = NULL;
	if (root->window)
		mlx_terminate(root->window);
}

void	game_error_and_exit(t_root *root, const char *err_msg)
{
	free_root(root);
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}
