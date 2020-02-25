/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:00:51 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 17:43:02 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <runtime_loop.h>
#include <ft_printf.h>
#include <stdio.h>
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
		return (2);
	}
	else if (readline_result == -1)
	{
		perror("failed to read line");
		return (1);
	}
	*input = line_buffer;
	return (0);
}
