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

#include <runtime_loop.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	signal_handler(int signal)
{
	int	pid;

	while (vector_pop(&g_running_processes, &pid))
		kill(pid, signal);
}

void	global_ctor(void)
{
	if (!vector_new(&g_running_processes, sizeof(int)))
	{
		perror("failed to initialize process stack");
		exit(1);
	}
	signal(SIGINT, signal_handler);
}

int		main(void)
{
	global_ctor();
	runtime_loop();
	return (0);
}
