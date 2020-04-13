/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:13 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:13 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*res;

	if (lst == NULL)
		return (NULL);
	out = NULL;
	while (lst != NULL)
	{
		res = ft_lstnew(f(lst->content));
		if (res == NULL)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		ft_lstadd_back(&out, res);
		lst = lst->next;
	}
	return (out);
}
