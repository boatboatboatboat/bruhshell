/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   take_char.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:49 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:49 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdio.h>

t_bool	take_char(
		char **input,
		char *c)
{
	*c = **input;
	*input += *c != '\0';
	return (*c != '\0');
}
