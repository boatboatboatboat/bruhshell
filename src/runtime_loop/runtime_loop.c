/* ************************************************************************** */
/*                                                                            */
/*   Project: memeshell420                                ::::::::            */
/*   Members: dpattij, tuperera                         :+:    :+:            */
/*   Copyright: 2020                                   +:+                    */
/*                                                    +#+                     */
/*                                                   +#+                      */
/*                                                  #+#    #+#                */
/*   while (!(succeed = try()));                   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <runtime_loop.h>
#include <parser.h>
#include <stdlib.h>
#include <ministd.h>

int		runtime_loop(void)
{
	char		*input_buffer;
	int			res;

	while (true)
	{
		if (display_prompt() != 0)
			break ;
		res = take_input(&input_buffer);
		if (res == 2)
			return (0);
		if (res == 1)
			break ;
		evaluate_input(input_buffer);
		free(input_buffer);
	}
	return (1);
}
