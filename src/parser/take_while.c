/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   take_while.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:50 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:50 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>

t_bool	take_whilen(
		char **input,
		char **output,
		t_bool (*matcher)(char),
		size_t n)
{
	size_t	length;

	length = 0;
	while ((*input)[length] != '\0' && matcher((*input)[length]))
		length += 1;
	if (length >= n)
	{
		if (output != NULL)
			*output = ft_substr(*input, 0, length);
		if (output != NULL && *output == NULL)
			return (false);
		*input += length;
	}
	return (length >= n);
}

t_bool	take_while(
		char **input,
		char **output,
		t_bool (*matcher)(char))
{
	return (take_whilen(input, output, matcher, 0));
}
