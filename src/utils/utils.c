/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 15:57:25 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/10 17:35:18 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

double	ft_abs_double(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

bool	valid_move(char **map, t_info *info, double y_plus, double x_plus)
{
	return (map[(int)(info->pos_y + y_plus)][(int)(info->pos_x
			+ x_plus)] != '1');
}

static const char	*after_dir(const char *argv)
{
	int	name_len;
	int	i;

	name_len = ft_strlen(argv);
	i = name_len - 1;
	while (i >= 0)
	{
		if (argv[i] == '/')
			return (&(argv[i + 1]));
		i--;
	}
	return (argv);
}

bool	is_cub_file(const char *filename)
{
	int			name_len;
	const char	*clean_filename;

	clean_filename = after_dir(filename);
	name_len = ft_strlen(clean_filename);
	if (name_len < 5)
		return (false);
	if (ft_strncmp(&(clean_filename[name_len - 4]), ".cub", 5) == 0)
		return (true);
	return (false);
}
