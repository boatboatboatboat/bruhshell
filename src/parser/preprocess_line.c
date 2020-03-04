/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 03:23:48 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/21 04:01:44 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_bool	filter_escape(
		char **input,
		t_vector *new_line)
{
	char	chr;
	size_t	n;

	while (take_char(input, &chr))
	{
		if (chr == '\033')
		{
			if (!(take_char(input, &chr) && chr == '['))
			{
				vector_destroy(new_line);
				return (false);
			}
			(void)take_number(input, &n);
			if (take_char(input, &chr))
				continue ;
		}
		else if (!vector_push(new_line, &chr))
			return (false);
	}
	return (true);
}

t_bool			sanitize_line(
		char **input,
		char **out)
{
	char		chr;
	t_vector	new_line;

	if (!vector_new(&new_line, sizeof(char)))
		return (false);
	filter_escape(input, &new_line);
	chr = '\0';
	if (!vector_push(&new_line, &chr))
		return (false);
	*out = new_line.raw;
	return (true);
}
