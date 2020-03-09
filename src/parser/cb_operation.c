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

#include <parser.h>

t_bool		cb_operation(
		char **input,
		t_instruction *operation)
{
	t_instruction	tmp;

	if (**input == '|')
		tmp.opcode = OP_PIPE;
	else if (**input == '<')
		tmp.opcode = OP_READ;
	else if (**input == '>')
	{
		tmp.opcode = (*input)[1] == '>' ? OP_APPEND : OP_WRITE;
		if ((*input)[1] == '>')
			*input += 1;
	}
	else
		return (false);
	*input += 1;
	take_while(input, NULL, is_literal_space);
	if (tmp.opcode == OP_WRITE || tmp.opcode == OP_READ
		|| tmp.opcode == OP_APPEND)
		if (!cb_item(input, &tmp.operand.filename))
			return (false);
	*operation = tmp;
	return (true);
}
