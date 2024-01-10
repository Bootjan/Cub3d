/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:03 by safoh             #+#    #+#             */
/*   Updated: 10/01/2024 16:46:58 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "scene.h"
#include "utils.h"

static void	process_character(char c, size_t *len, bool *found_player)
{
	if (c == '\n')
	{
		if (*len <= 1)
			user_error_and_exit("Empty line in map");
		*len = 0;
	}
	else if (is_valid_character(c) == false)
	{
		user_error_and_exit("Invalid character in map");
	}
	else if (is_player(c) == true)
	{
		if (*found_player == true)
			user_error_and_exit("too many players in map");
		*found_player = true;
	}
}

void	check_valid_map(const char *string)
{
	size_t	i;
	size_t	len;
	bool	found_player;

	i = 0;
	len = 0;
	found_player = false;
	while (string[i])
	{
		process_character(string[i], &len, &found_player);
		len++;
		i++;
	}
	if (found_player == false)
		user_error_and_exit("No player in map");
}
