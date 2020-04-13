/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isinset.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:06 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:06 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinset(char c, const char *set)
{
	t_size	idx;

	idx = 0;
	while (set[idx] != c && set[idx] != '\0')
		idx += 1;
	return (set[idx] == c);
}
