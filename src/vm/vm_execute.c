/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_execute.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:13 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:13 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_dispatch_item	g_dispatch_table[7] =
{
	{OP_COMMAND, handle_op_command},
	{OP_CALL, handle_op_call},
	{OP_PIPE, handle_op_pipe},
	{OP_WRITE, handle_op_write},
	{OP_READ, handle_op_read},
	{OP_APPEND, handle_op_append},
	{OP_NOP, NULL},
};

int		execute_opcode(
		t_instruction *instruction,
		t_vm_state *state)
{
	if (g_dispatch_table[instruction->opcode].opcode != OP_NOP)
		return (g_dispatch_table[instruction->opcode].fn(instruction, state));
	return (1);
}

int		destroy_state(t_vm_state *state)
{
	vector_destroy(&state->callstack);
	vector_destroy(&state->pipestack);
	return (0);
}

/*
** vm_execute:
**  take a list of instructions and execute them
**
** this setup uses a pipe and call stack:
**
** the command 'echo hello'
** would be compiled into
**
** OP_COMMAND { PAIR: { NAME: "echo", ARGS: { "echo", "hello" } } }
** OP_CALL
**
** the pipe stack is initialized with just the value -1.
** (i.e.: pipe stack { -1 })
**
** OP_COMMAND will place the command pair onto the call stack.
** (i.e.: call stack { PAIR { "echo", {"echo", "hello"} } }
** OP_CALL will go through the command stack from first-to-last,
** and execute every command on the stack.
**
** each command is given a set of pipes, given through a sliding window,
**  shifting by one.
** (i.e.:
**   command 1 gets pipes 1, 2
**   command 2 gets pipes 2, 3
**   command 3 gets pipes 3, 4
**   command n gets pipes n, n + 1)
**
** OP_PIPE will place a new set of pipes on the pipe stack.
** OP_APPEND will open a file in append mode, and place it on an 'even' pipe.
** OP_READ will open a file in read mode, and place it on an 'uneven' pipe.
** OP_WRITE will open a file in truncate mode, and place it on an 'even' pipe.
**
** There is an unused debug instruction called OP_NOP (No Operation),
**  which does nothing.
*/

int		vm_execute(
		t_vector *instructions,
		t_table *env)
{
	t_vm_state		state;
	int				dummy;

	state.env = env;
	dummy = -1;
	if (!(vector_new(&state.pipestack, sizeof(int))
	&& vector_new(&state.callstack, sizeof(t_command_pair))))
		return (destroy_state(&state));
	if (!vector_push(&state.pipestack, &dummy))
		return (destroy_state(&state));
	if (!vector_foreachc(instructions, (int (*)(void *, void *)) execute_opcode,
			&state))
		return (destroy_state(&state));
	destroy_state(&state);
	return (1);
}
