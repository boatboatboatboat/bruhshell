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

#include <vm.h>
#include <builtin.h>
#include <libft.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <signal.h>

const int	g_no_pipes[2] =
{
	-1,
	-1
};

void	get_pipes(
		t_vm_state *state,
		size_t idx,
		int pipe_temp[2])
{
	int prog_pipe;

	if (vector_get(&state->pipestack, idx * 2, &prog_pipe))
	{
		pipe_temp[0] = prog_pipe;
		if (vector_get(&state->pipestack, idx * 2 + 1, &prog_pipe))
			pipe_temp[1] = prog_pipe;
		else
			pipe_temp[1] = -1;
	}
	else
		ft_memcpy(pipe_temp, g_no_pipes, sizeof(g_no_pipes));
}

int		spawn_process(
		t_vm_state *state,
		t_command_pair *command,
		size_t idx,
		int pipe_temp[2])
{
	int		pid;
	int		status;
	char	*destructor;

	if (is_builtin(command->command))
		pid = run_builtin(&command->args, &state->pipestack,
				pipe_temp, &state->env);
	else
		pid = run_process(&command->args, &state->pipestack, pipe_temp,
				&state->env);
	if ((idx + 1) == state->callstack.size)
	{
		waitpid(pid, &status, 0);
		ft_printf("%d finished with %d.\n", pid, WEXITSTATUS(status));
		kill(pid, SIGINT);
	}
	while (vector_pop(&command->args, &destructor))
		free(destructor);
	vector_destroy(&command->args);
	return (pid != -1);
}

int		handle_op_call(
		t_instruction *instruction,
		t_vm_state *state)
{
	size_t			idx;
	int				pipe_temp[2];
	t_command_pair	*command;

	idx = 0;
	while (idx < state->callstack.size)
	{
		vector_getr(&state->callstack, idx, (void **)&command);
		get_pipes(state, idx, pipe_temp);
		if (!spawn_process(state, command, idx, pipe_temp))
			return (0);
		idx += 1;
	}
	vector_destroy(&state->callstack);
	vector_destroy(&state->pipestack);
	if (!(vector_new(&state->pipestack, sizeof(int))
		& vector_new(&state->callstack, sizeof(t_command_pair))))
		return (0);
	instruction->opcode = -1;
	if (!vector_push(&state->pipestack, &instruction->opcode))
		return (0);
	return (1);
}
