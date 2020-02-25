/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:03:42 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 17:46:36 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <runtime_loop.h>
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
		free(input_buffer);
	}
	return (1);
}
