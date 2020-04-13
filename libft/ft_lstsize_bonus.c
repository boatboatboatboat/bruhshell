/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:15 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:15 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		length;

	length = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = curr->next;
		length += 1;
	}
	return (length);
}
