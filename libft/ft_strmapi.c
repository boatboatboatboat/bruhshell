/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:29 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:29 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	t_size			length;
	char			*out;

	if (s == NULL || f == NULL)
		return (NULL);
	index = 0;
	length = ft_strlen(s);
	out = ft_calloc(length + 1, sizeof(char));
	if (out == NULL)
		return (NULL);
	while (index < length)
	{
		out[index] = f(index, s[index]);
		index += 1;
	}
	out[index] = '\0';
	return (out);
}
