/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skip_atleast.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:48 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:48 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool	skip_atleast(
		char **input,
		char matcher,
		size_t times)
{
	size_t occurs;

	occurs = 0;
	while ((*input)[occurs] == matcher)
		occurs += 1;
	*input += occurs;
	return (occurs >= times);
}
