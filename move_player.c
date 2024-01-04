/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 16:54:40 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/04 17:37:50 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_info *info, char **map)
{
	if (map[(int)info->posY][(int)(info->posX + info->dirX * MOVE_SPEED)] == '0')
		info->posX += info->dirX * MOVE_SPEED;
	if (map[(int)(info->posY + info->dirY * MOVE_SPEED)][(int)info->posX])
		info->posY += info->dirY * MOVE_SPEED;
}

static void	move_backwards(t_info *info, char **map)
{
	if (map[(int)info->posY][(int)(info->posX - info->dirX * MOVE_SPEED)] == '0')
		info->posX -= info->dirX * MOVE_SPEED;
	if (map[(int)(info->posY - info->dirY * MOVE_SPEED)][(int)info->posX] == '0')
		info->posY -= info->dirY * MOVE_SPEED;
}

static void	move_right(t_info *info, char **map)
{
	if (map[(int)info->posY][(int)(info->posX - info->dirY * MOVE_SPEED)] == '0')
		info->posX -= info->dirY * MOVE_SPEED;
	if (map[(int)(info->posY + info->dirX * MOVE_SPEED)][(int)info->posX] == '0')
		info->posY += info->dirX * MOVE_SPEED;
}

static void	move_left(t_info *info, char **map)
{
	if (map[(int)(info->posY)][(int)(info->posX + info->dirY * MOVE_SPEED)] == '0')
		info->posX += info->dirY * MOVE_SPEED;
	if (map[(int)(info->posY - info->dirX * MOVE_SPEED)][(int)info->posX] == '0')
		info->posY -= info->dirX * MOVE_SPEED;
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
