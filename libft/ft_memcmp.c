/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:19 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:19 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, t_size length)
{
	const unsigned char	*cast_str1;
	const unsigned char	*cast_str2;
	t_size				index;

	index = 0;
	cast_str1 = str1;
	cast_str2 = str2;
	while (index < length)
	{
		if (cast_str1[index] != cast_str2[index])
			return (cast_str1[index] - cast_str2[index]);
		index += 1;
	}
	return (0);
}
