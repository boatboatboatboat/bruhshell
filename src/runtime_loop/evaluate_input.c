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

int		expand_evaluate(t_string_slice *command)
{
	t_vector	instructions;

	if (!vector_new(&instructions, sizeof(t_instruction)))
		return (0);
	command->str[command->len] = '\0';
	if (!parse_line(&command->str, &instructions))
	{
		ft_printf("parser error: failed to parse line\n");
		return (0);
	}
	vm_execute(&instructions, NULL);
	return (1);
}

int		evaluate_input(char *input)
{
	t_vector		commands;

	if (!vector_new(&commands, sizeof(t_string_slice)))
		return (1);
	if (!seperate_commands(input, &commands))
	{
		ft_printf("parser error: command seperation failed\n");
		vector_destroy(&commands);
		return (1);
	}
	vector_foreach(&commands, (int (*)(void *))dbg_print_sslice);
	vector_foreach(&commands, (int (*)(void *))expand_evaluate);
	vector_destroy(&commands);
	return (0);
}
