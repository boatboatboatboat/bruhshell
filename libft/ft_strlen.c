/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:28 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:28 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size		ft_strlen(const char *str)
{
	t_size	length;

	length = 0;
	while (str[length] != 0)
		length += 1;
	return (length);
}
