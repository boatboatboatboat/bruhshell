/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:21 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:21 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size length)
{
	t_size	idx;

	if (length == 0 || dest == src)
		return (dest);
	idx = (dest < src) ? 0 : length;
	if (dest < src)
		ft_memcpy(dest, src, length);
	else
		while (idx > 0)
		{
			idx -= 1;
			((unsigned char *)dest)[idx] = ((const unsigned char *)src)[idx];
		}
	return (dest);
}
