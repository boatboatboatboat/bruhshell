/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:36:11 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/15 23:47:30 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_realloc(
		char *ptr,
		int ocapacity,
		int capacity)
{
	char	*new;
	int		idx;

	new = malloc(capacity * sizeof(char));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	idx = 0;
	while (idx < ocapacity)
	{
		new[idx] = ptr[idx];
		idx += 1;
	}
	free(ptr);
	return (new);
}
