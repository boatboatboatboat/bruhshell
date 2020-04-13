/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:35 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:35 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_realloc(
		char *ptr,
		size_t ocapacity,
		size_t capacity)
{
	char	*new;
	size_t	idx;

	new = malloc(capacity * sizeof(char));
	if (new == NULL)
		return (NULL);
	idx = 0;
	while (idx < ocapacity)
	{
		new[idx] = ptr[idx];
		idx += 1;
	}
	free(ptr);
	return (new);
}
