/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:14:19 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 20:05:10 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <vector.h>

t_bool	seperate_commands(
		t_parser_result *result,
		t_parser_object *parser,
		t_vector *commands)
{
	t_string_slice	str;

	if (!vector_new(commands, sizeof(t_string_slice)))
		return (false);
	str = parser->input;
	while (true)
	{
		skip_while(parser, not_string_quotes_or_cmd_seperator);
		if (parser->input.str[0] == CMD_SEPERATOR)
		{
			str.len = parser->input.str - str.str;
			if (!vector_push(commands, &str))
				return (false);
		}
		else if (cb_single_string_check(parser_obj, false))
			;
		else if (cb_double_string_check(parser_obj, false))
			;
	}
}
