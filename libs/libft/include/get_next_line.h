/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 15:48:21 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/08 16:49:11 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# define SIZE_OF_CHAR 1

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_index_n(const char *str, char c);
char	*ft_tempdup(char *buffer);
char	*ft_tempjoin(char **temp, char *buffer);
char	*free_temp(char **str);
char	*get_next_line(int fd);

#endif
