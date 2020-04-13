/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsetcount.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:33 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:33 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size		ft_strsetcount(const char *str, const char *set)
{
	t_size	count;
	t_size	set_idx;
	t_size	str_idx;

	count = 0;
	set_idx = 0;
	str_idx = 0;
	while (str[str_idx] != 0)
	{
		while (str[str_idx] != set[set_idx] && set_idx < ft_strlen(set))
			set_idx += 1;
		if (str[str_idx] != set[set_idx])
			count += 1;
		set_idx = 0;
		str_idx += 1;
	}
	return (count);
}
