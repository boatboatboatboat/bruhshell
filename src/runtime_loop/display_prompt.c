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

#include <ft_printf.h>
#include <runtime_loop.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		display_prompt(void)
{
	char	*current_directory;

	current_directory = getcwd(NULL, 0);
	if (current_directory == NULL)
	{
		perror("unable to get working directory");
		return (1);
	}
	ft_printf(PROMPT_STRING, current_directory);
	free(current_directory);
	return (0);
}
