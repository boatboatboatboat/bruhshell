/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:21 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:21 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *byte_string, int value, t_size length)
{
	t_size	idx;

	idx = 0;
	while (idx < length)
	{
		((unsigned char *)byte_string)[idx] = (unsigned char)value;
		idx += 1;
	}
	return (byte_string);
}
