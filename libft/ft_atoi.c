/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:05:02 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:05:02 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	output;
	t_size			idx;
	int				sign;

	sign = 0;
	output = 0;
	idx = 0;
	while (ft_isspace(str[idx]))
		idx += 1;
	if (str[idx] == '-')
		sign = 1;
	idx += str[idx] == '+' || str[idx] == '-';
	while (ft_isdigit(str[idx]))
	{
		output = (output * 10) + str[idx] - '0';
		idx += 1;
	}
	if (sign && (output >= (unsigned)(LONG_MAX - 1)))
		return (0);
	else if (output >= (unsigned)LONG_MAX)
		return (-1);
	return ((int)(sign ? -output : output));
}
