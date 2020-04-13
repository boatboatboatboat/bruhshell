/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:11 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:11 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*old;

	if (lst == NULL || del == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		del(curr->content);
		old = curr;
		curr = curr->next;
		free(old);
	}
	*lst = NULL;
}
