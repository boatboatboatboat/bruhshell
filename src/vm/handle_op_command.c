/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_op_command.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:01:47 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:01:47 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int	handle_op_command(
		t_instruction *instruction,
		t_vm_state *state)
{
	return (vector_push(&state->callstack,
			(void **)&instruction->operand.pair));
}
