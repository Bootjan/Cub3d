/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_error_and_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:21:46 by safoh             #+#    #+#             */
/*   Updated: 2024/01/10 16:21:47 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	user_error_and_exit(const char *message)
{
	printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}
