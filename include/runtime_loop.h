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

#ifndef RUNTIME_LOOP_H
# define RUNTIME_LOOP_H

# define PROMPT_STRING "\033[31;1m%s\033[0m > "

# include <vector.h>

static t_vector	g_running_processes;

int				runtime_loop(void);
int				display_prompt(void);
int				read_char(char *out);
int				read_line(
				char **line,
				int eof_matters);
int				take_input(char **input);

#endif
