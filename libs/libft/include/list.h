/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: afoh <safoh@student.codam.nl>                +#+                     */
/*                                                   +#+                      */
/*   Created: 0008/01/20 12:51:53 by y safoh       #+#    #+#                 */
/*   Updated: 2024/01/08 16:48:14 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **alst, t_list *new);

void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
