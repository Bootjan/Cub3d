/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:23:30 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:23:31 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdlib.h>

bool	is_valid_character(char c);
bool	is_player(char c);
void	print_str_table(char **table);
size_t	max_col_len(char **map);
size_t	row_len(char **map);

#endif
