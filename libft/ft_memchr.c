/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:19 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:19 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int occur, t_size length)
{
	unsigned char		*cast_string;
	unsigned char		cast_occur;
	t_size				index;

	cast_occur = (unsigned char)occur;
	cast_string = (unsigned char *)string;
	index = 0;
	while (index < length)
	{
		if (cast_string[index] == cast_occur)
			return (cast_string + index);
		index += 1;
	}
	return (NULL);
}
