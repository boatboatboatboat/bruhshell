/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:20 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:20 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, t_size length)
{
	t_size	idx;

	if (dest == src)
		return (dest);
	idx = 0;
	while (idx < length)
	{
		((unsigned char *)dest)[idx] = ((const unsigned char *)src)[idx];
		idx += 1;
	}
	return (dest);
}
