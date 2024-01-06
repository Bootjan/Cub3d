/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:07:37 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/06 17:32:56 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*convert_pixels(uint8_t *pixels)
{
	int			i;
	int			*new_pixels;

	i = 0;
	new_pixels = ft_calloc(TEX_SIZE * TEX_SIZE, sizeof(int));
	if (!new_pixels)
		return (NULL);
	while (i < TEX_SIZE * TEX_SIZE)
	{
		new_pixels[i] = compute_color(pixels[4 * i], pixels[4 * i + 1], \
		pixels[4 * i + 2], pixels[4 * i + 3]);
		i++;
	}
	return (new_pixels);
}

static mlx_image_t	*load_image(mlx_t *window, \
const char *path, int *error_flag)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		return (*error_flag = 1, NULL);
	image = mlx_texture_to_image(window, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (*error_flag = 1, NULL);
	if (!mlx_resize_image(image, TEX_SIZE, TEX_SIZE))
		return (*error_flag = 1, NULL);
	return (image);
}

int	*load_pixels(mlx_t *window, const char *path, int *error_flag)
{
	int				*pixels;
	mlx_image_t		*image;

	if (*error_flag != 0)
		return (NULL);
	image = load_image(window, path, error_flag);
	if (!image)
		return (NULL);
	pixels = convert_pixels(image->pixels);
	if (!pixels)
		return (*error_flag = 1, NULL);
	return (pixels);
}

int	load_textures(t_root *root)
{
	int			error_flag;

	error_flag = 0;
	root->no_texture = load_pixels(root->window, root->no_path, &error_flag);
	root->so_texture = load_pixels(root->window, root->so_path, &error_flag);
	root->ea_texture = load_pixels(root->window, root->ea_path, &error_flag);
	root->we_texture = load_pixels(root->window, root->we_path, &error_flag);
	if (error_flag != 0)
		return (-1);
	return (0);
}

t_root	*init_mlx(t_root *root)
{
	int	image_index;

	root->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D...", true);
	if (!root->window)
		return (printf("Error\n"), free_root(&root), NULL);
	if (load_textures(root) != 0)
		return (error_mlx(&root));
	root->image = mlx_new_image(root->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!root->image)
		return (error_mlx(&root));
	image_index = mlx_image_to_window(root->window, root->image, 0, 0);
	if (image_index == -1)
		return (error_mlx(&root));
	root->color_ceil = compute_color_rgb(root->rgb_ceil);
	root->color_floor = compute_color_rgb(root->rgb_floor);
	return (root);
}
