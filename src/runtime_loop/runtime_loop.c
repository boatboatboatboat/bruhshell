/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   runtime_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:40 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:40 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <runtime_loop.h>
#include <parser.h>
#include <stdlib.h>
#include <ministd.h>

/*
** core loop of the shell,
** consists out of:
** 1. displaying a prompt
** 2. reading a line (taking input)
** 3. evaluating the line (running the 'code' in the line)
*/

int		runtime_loop(t_table *env)
{
	char		*input_buffer;
	int			res;

	while (true)
	{
		if (display_prompt(env) != DISPLAY_PROMPT_SUCCESS)
			break ;
		res = take_input(&input_buffer);
		if (res == TAKE_INPUT_EXIT_CALLED)
			return (RUNTIME_LOOP_EXIT);
		if (res == TAKE_INPUT_READLINE_FAILED)
			break ;
		evaluate_input(input_buffer, env);
		free(input_buffer);
	}
	return (RUNTIME_LOOP_CRASH);
}
