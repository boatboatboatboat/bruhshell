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

#include <vector.h>
#include <parser.h>
#include <ft_printf.h>
#include <stdlib.h>

/*
** Three step parser:
** seperate (seperate commands with ;)
** foreach:
**  expand (expand variables within a single command)
**  evaluate (evaluate the comamnd
*/

int		dbg_print_sslice(t_string_slice *slice)
{
	size_t	idx;

	idx = 0;
	ft_printf("[");
	while (idx < slice->len)
	{
		ft_printf("%c", slice->str[idx]);
		idx += 1;
	}
	ft_printf("]\n");
	return (1);
}

int		expand_evaluate(
		t_string_slice *command,
		t_table *env)
{
	t_vector	instructions;

	if (!vector_new(&instructions, sizeof(t_instruction)))
		return (0);
	command->str[command->len] = '\0';
	if (!parse_line(&command->str, &instructions))
	{
		ft_printf("eval error: failed to parse line\n");
		return (0);
	}
	if (!vm_execute(&instructions, env))
	{
		ft_printf("eval error: virtual machine crashed\n");
		return (0);
	}
	return (1);
}

int		evaluate_input(
		char *input,
		t_table *env)
{
	t_vector		commands;
	char			*sanitized;

	if (!vector_new(&commands, sizeof(t_string_slice)))
		return (1);
	if (!sanitize_line(&input, &sanitized))
	{
		ft_printf("preprocessor error: line sanitization failed\n");
		vector_destroy(&commands);
		return (1);
	}
	if (!seperate_commands(sanitized, &commands))
	{
		ft_printf("preprocessor error: command seperation failed\n");
		vector_destroy(&commands);
		return (1);
	}
	vector_foreachc(&commands, (int (*)(void *, void *))expand_evaluate, env);
	vector_destroy(&commands);
	free(sanitized);
	return (0);
}
