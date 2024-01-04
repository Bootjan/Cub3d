/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:07:37 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/04 02:14:29 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t	*load_image(mlx_t *window, const char *path, int *error_flag)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	if (*error_flag != 0)
		return (NULL);
	texture = mlx_load_png(path);
	if (!texture)
		return (*error_flag = 1, NULL);
	image = mlx_texture_to_image(root->window, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (*error_flag = 1, NULL);
	if (!mlx_resize_image(image, IMAGE_SIZE, IMAGE_SIZE))
		return (*error_flag = 1, NULL);
	return (image);
}

int	load_images(t_root *root)
{
	int	error_flag;

	error_flag = 0;
	root->no_image = load_image(root->window, PATH, &error_flag);
	root->ea_image = load_image(root->window, PATH, &error_flag);
	root->so_image = load_image(root->window, PATH, &error_flag);
	root->we_image = load_image(root->window, PATH, &error_flag);
	if (error_flag != 0)
		return (-1);
	return (0);
}

mlx_t	*compute_root(void)
{
	t_root	*root;

	root = ft_calloc(1, sizeof(t_root));
	if (!root)
		return (NULL);
	root->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D...", true);
	if (!root->window)
		return (printf("Error\n"), free(root), NULL); // Better error messages
	root->image = mlx_new_image(root->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!root->image)
		return (mlx_terminate(root->window), printf("Error\n"), free(root), NULL); // Better error messages
	root->imageIndex = mlx_image_to_window(root->window, root->image, 0, 0);
	if (root->imageIndex == -1)
		return (mlx_terminate(root->window), printf("Error\n"), free(root), NULL); // Better error messages
	// if (load_images(root) != 0) // add different paths for images
	// 	return (mlx_terminate(root->window), printf("Error\n"), free(root), NULL); // Better error messages
	return (root);
}
