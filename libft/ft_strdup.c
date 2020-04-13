/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:26 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:26 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	t_size	len;

	len = ft_strlen(str) + 1;
	dup = ft_calloc(len, sizeof(char));
	if (dup == NULL)
		return (NULL);
	return (ft_memcpy(dup, str, len));
}
