/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   take_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:41 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:41 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <runtime_loop.h>
#include <ft_printf.h>
#include <stdlib.h>

int	take_input(char **input)
{
	int		readline_result;
	char	*line_buffer;

	readline_result = read_line(&line_buffer, 1);
	if (readline_result == 0 && line_buffer[0] == '\0')
	{
		free(line_buffer);
		ft_printf("exit\n");
		return (TAKE_INPUT_EXIT_CALLED);
	}
	else if (readline_result == -1)
	{
		ft_perror("failed to read line");
		return (TAKE_INPUT_READLINE_FAILED);
	}
	*input = line_buffer;
	return (TAKE_INPUT_SUCCESS);
}
