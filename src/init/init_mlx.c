/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 01:07:37 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/10 18:03:17 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_pixels(uint8_t *pixels, int *new_pixels)
{
	int	i;

	i = 0;
	while (i < TEX_SIZE * TEX_SIZE)
	{
		new_pixels[i] = compute_color(pixels[4 * i], pixels[4 * i + 1], \
		pixels[4 * i + 2], pixels[4 * i + 3]);
		i++;
	}
}

static mlx_image_t	*load_image(t_root *root, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		game_error_and_exit(root, "mlx_load_png failed in load_image");
	image = mlx_texture_to_image(root->window, texture);
	mlx_delete_texture(texture);
	if (!image)
		game_error_and_exit(root, "mlx_load_png failed in load_image");
	if (!mlx_resize_image(image, TEX_SIZE, TEX_SIZE))
		game_error_and_exit(root, "mlx_load_png failed in load_image");
	return (image);
}

void	load_pixels(t_root *root, const char *path, int *texture)
{
	mlx_image_t	*image;

	image = load_image(root, path);
	convert_pixels(image->pixels, texture);
}

void	load_textures(t_root *root)
{
	load_pixels(root, root->no_path, root->no_texture);
	load_pixels(root, root->so_path, root->so_texture);
	load_pixels(root, root->ea_path, root->ea_texture);
	load_pixels(root, root->we_path, root->we_texture);
}

void	init_mlx(t_root *root)
{
	int	image_index;

	root->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D...", true);
	if (!root->window)
		game_error_and_exit(root, "mlx_init in init_mlx");
	load_textures(root);
	root->image = mlx_new_image(root->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!root->image)
		game_error_and_exit(root, "mlx_new_image in init_mlx");
	image_index = mlx_image_to_window(root->window, root->image, 0, 0);
	if (image_index == -1)
		game_error_and_exit(root, "mlx_image_to_window in init_mlx");
	root->color_ceil = compute_color_rgb(root->rgb_ceil);
	root->color_floor = compute_color_rgb(root->rgb_floor);
}
