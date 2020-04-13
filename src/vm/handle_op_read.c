/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_op_read.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:10 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:10 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#include <fcntl.h>
#include <stdlib.h>

int	handle_op_read(
		t_instruction *instruction,
		t_vm_state *state)
{
	int	*previous_pipe;

	if (state->pipestack.size == 1)
		vector_getr(&state->pipestack, 0, (void **)&previous_pipe);
	else
		vector_getr(&state->pipestack, state->pipestack.size - 1,
				(void **)&previous_pipe);
	*previous_pipe = open(instruction->operand.filename, O_RDONLY);
	if (*previous_pipe == -1)
		ft_perror("failed to open file");
	return (1);
}
