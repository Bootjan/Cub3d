/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:07:37 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 00:25:39 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	compute_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	*convert_pixels(uint8_t *pixels)
{
	int			i;
	int			*newPixels;

	i= 0;
	newPixels = ft_calloc(TEX_SIZE * TEX_SIZE, sizeof(int));
	if (!newPixels)
		return (NULL);
	while (i < TEX_SIZE * TEX_SIZE)
	{
		newPixels[i] = compute_color(pixels[4 * i], pixels[4 * i + 1], \
		pixels[4 * i + 2], pixels[4 * i + 3]);
		i++;
	}
	return (newPixels);
}

int	*load_pixels(mlx_t *window, const char *path, int *error_flag)
{
	int				*pixels;
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	if (*error_flag != 0)
		return (NULL);
	texture = mlx_load_png(path);
	if (!texture)
		return (*error_flag = 1, NULL);
	image = mlx_texture_to_image(window, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (*error_flag = 1, NULL);
	if (!mlx_resize_image(image, TEX_SIZE, TEX_SIZE))
		return (*error_flag = 1, NULL);
	pixels = convert_pixels(image->pixels);
	if (!pixels)
		return (*error_flag = 1, NULL);
	return (pixels);
}

int	load_textures(t_root *root)
{
	int			error_flag;

	error_flag = 0;
	root->noTexture = load_pixels(root->window, PATH2, &error_flag);
	root->soTexture = load_pixels(root->window, PATH, &error_flag);
	root->eaTexture = load_pixels(root->window, PATH4, &error_flag);
	root->weTexture = load_pixels(root->window, PATH3, &error_flag);
	if (error_flag != 0)
		return (-1);
	return (0);
}

t_root	*compute_root(void)
{
	t_root	*root;

	root = ft_calloc(1, sizeof(t_root));
	if (!root)
		return (NULL);
	root->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D...", true);
	if (!root->window)
		return (printf("Error\n"), free(root), NULL); // Better error messages
	if (load_textures(root) != 0)
		return (mlx_terminate(root->window), printf("Error\n"), free(root), NULL);
	root->image = mlx_new_image(root->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!root->image)
		return (mlx_terminate(root->window), printf("Error\n"), free(root), NULL); // Better error messages
	root->imageIndex = mlx_image_to_window(root->window, root->image, 0, 0);
	if (root->imageIndex == -1)
		return (mlx_terminate(root->window), printf("Error\n"), free(root), NULL); // Better error messages
	// root->color_ceil = compute_color(root->rgb_ceil[0], root->rgb_ceil[1], root->rgb_ceil[2], 255);
	// root->color_floor = compute_color(root->rgb_floor[0], root->rgb_floor[1], root->rgb_floor[2], 255);
	return (root);
}