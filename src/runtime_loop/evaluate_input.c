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

static int	evaluate_unit(
		char *line,
		t_table *env)
{
	char		*pline_cpy;
	t_vector	instructions;

	if (!vector_new(&instructions, sizeof(t_instruction)))
		return (0);
	pline_cpy = line;
	if (!parse_line(&pline_cpy, &instructions))
	{
		ft_printf("eval error: failed to parse line\n");
		vector_destroy(&instructions);
		return (0);
	}
	if (!vm_execute(&instructions, env))
	{
		ft_printf(("eval error: virtual machine crashed\n"));
		vector_destroy(&instructions);
		return (0);
	}
	vector_destroy(&instructions);
	return (1);
}

static int	expand_evaluate(
		t_string_slice *command,
		t_table *env)
{
	char		*line;

	command->str[command->len] = '\0';
	if (!expand_line(command->str, env, &line))
	{
		ft_printf("eval error: failed to expand line\n");
		return (0);
	}
	if (!evaluate_unit(line, env))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int			evaluate_input(
		char *input,
		t_table *env)
{
	t_vector		commands;
	char			*sanitized;

	if (!vector_new(&commands, sizeof(t_string_slice)))
		return (1);
	if (!sanitize_line(&input, &sanitized))
	{
		ft_printf("preprocessor error: failed to sanitize line\n");
		vector_destroy(&commands);
		return (1);
	}
	if (!seperate_commands(sanitized, &commands))
	{
		ft_printf("preprocessor error: failed to seperate commands\n");
		free(sanitized);
		vector_destroy(&commands);
		return (1);
	}
	vector_foreachc(&commands, (int (*)(void *, void *))expand_evaluate, env);
	vector_destroy(&commands);
	free(sanitized);
	return (0);
}
