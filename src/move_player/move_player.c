/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:54:40 by bschaafs          #+#    #+#             */
/*   Updated: 2024/01/07 20:34:07 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_info *info, char **map)
{
	if (valid_move(map, info, 0, info->dir_x * MOVE_SPEED * 2))
		info->pos_x += info->dir_x * MOVE_SPEED;
	if (valid_move(map, info, info->dir_y * MOVE_SPEED * 2, 0))
		info->pos_y += info->dir_y * MOVE_SPEED;
}

static void	move_backwards(t_info *info, char **map)
{
	if (valid_move(map, info, 0, -info->dir_x * MOVE_SPEED * 2))
		info->pos_x -= info->dir_x * MOVE_SPEED;
	if (valid_move(map, info, -info->dir_y * MOVE_SPEED * 2, 0))
		info->pos_y -= info->dir_y * MOVE_SPEED;
}

static void	move_right(t_info *info, char **map)
{
	if (valid_move(map, info, 0, -info->dir_y * MOVE_SPEED * 2))
		info->pos_x -= info->dir_y * MOVE_SPEED;
	if (valid_move(map, info, info->dir_x * MOVE_SPEED * 2, 0))
		info->pos_y += info->dir_x * MOVE_SPEED;
}

static void	move_left(t_info *info, char **map)
{
	if (valid_move(map, info, 0, info->dir_y * MOVE_SPEED * 2))
		info->pos_x += info->dir_y * MOVE_SPEED;
	if (valid_move(map, info, -info->dir_x * MOVE_SPEED * 2, 0))
		info->pos_y -= info->dir_x * MOVE_SPEED;
}

void	move_player(void *arg)
{
	t_root	*root;

	root = (t_root *)arg;
	if (mlx_is_key_down(root->window, MLX_KEY_ESCAPE))
		mlx_close_window(root->window);
	if (mlx_is_key_down(root->window, MLX_KEY_W))
		move_forward(root->info, root->map);
	if (mlx_is_key_down(root->window, MLX_KEY_S))
		move_backwards(root->info, root->map);
	if (mlx_is_key_down(root->window, MLX_KEY_A))
		move_left(root->info, root->map);
	if (mlx_is_key_down(root->window, MLX_KEY_D))
		move_right(root->info, root->map);
	if (mlx_is_key_down(root->window, MLX_KEY_LEFT))
		turn_left(root->info);
	if (mlx_is_key_down(root->window, MLX_KEY_RIGHT))
		turn_right(root->info);
}
