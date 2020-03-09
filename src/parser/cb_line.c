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
#include <stdlib.h>

/*
** warning:
** this function DOES modify t_vector *instructions,
** even if it fails!
** therefore the exception handler for parse_line should
**    call the destructor on its contents as well.
*/

static void		destroy_instruction(t_instruction instruction)
{
	char	*tmp;

	if (instruction.opcode == OP_COMMAND)
	{
		while (vector_pop(&instruction.operand.pair.args, &tmp))
			free(tmp);
		vector_destroy(&instruction.operand.pair.args);
	}
	else if (instruction.opcode != OP_CALL && instruction.opcode != OP_PIPE)
		free(instruction.operand.filename);
}

static t_bool	parse_op_and_com(
		char **input,
		t_vector *instructions,
		t_bool *success)
{
	t_instruction	instruction;

	*success = **input == '\0';
	while (cb_operation(input, &instruction))
	{
		*success = true;
		if (!vector_push(instructions, &instruction))
		{
			free(instruction.operand.filename);
			return (false);
		}
		if (cb_command(input, &instruction.operand.pair))
		{
			instruction.opcode = OP_COMMAND;
			if (!vector_push(instructions, &instruction))
				destroy_instruction(instruction);
		}
		else if (instruction.opcode == OP_PIPE)
			return (false);
	}
	return (true);
}

static t_bool	clean_instructions(t_vector *instructions)
{
	t_instruction	out;

	while (vector_pop(instructions, &out))
		destroy_instruction(out);
	return (false);
}

t_bool			parse_line(
		char **input,
		t_vector *instructions)
{
	t_instruction	instruction;
	t_bool			success;

	take_while(input, NULL, is_literal_space);
	if (**input == '\0')
		return (true);
	if (cb_command(input, &instruction.operand.pair))
	{
		instruction.opcode = OP_COMMAND;
		if (!vector_push(instructions, &instruction))
			return (clean_instructions(instructions));
		if (!parse_op_and_com(input, instructions, &success) || !success)
			return (clean_instructions(instructions));
		instruction.opcode = OP_CALL;
		if (!vector_push(instructions, &instruction))
		{
			destroy_instruction(instruction);
			return (clean_instructions(instructions));
		}
		return (true);
	}
	return (false);
}
