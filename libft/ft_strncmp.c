/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:30 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:30 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *str1, const char *str2, t_size length)
{
	t_size	index;

	index = 0;
	while (index < length)
	{
		if (str1[index] == '\0' || str1[index] != str2[index])
			break ;
		index += 1;
	}
	if (index == length)
		return (0);
	else
		return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
