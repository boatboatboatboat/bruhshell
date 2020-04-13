/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:32 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:32 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	char	cast_occur;
	t_size	index;

	index = ft_strlen(str) + 1;
	cast_occur = (char)chr;
	while (index > 0)
	{
		index -= 1;
		if (str[index] == cast_occur)
			return ((char *)(str + index));
	}
	return (NULL);
}
