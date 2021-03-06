/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   take_number.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:49 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:49 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

t_bool			take_number(
		char **input,
		size_t *out)
{
	size_t		res;

	res = 0;
	if (!is_digit(**input))
		return (false);
	while (is_digit(**input))
	{
		res = res * 10 + (**input - '0') % 10;
		*input += 1;
	}
	*out = res;
	return (true);
}
