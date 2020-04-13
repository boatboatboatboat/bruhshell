/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:18 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:18 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int term, t_size length)
{
	t_size			idx;
	unsigned char	*cast_dest;
	unsigned char	*cast_src;

	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	idx = 0;
	while (idx < length)
	{
		cast_dest[idx] = cast_src[idx];
		if (cast_dest[idx] == (unsigned char)term)
			return (cast_dest + idx + 1);
		idx += 1;
	}
	return (NULL);
}
