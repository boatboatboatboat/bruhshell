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
# define PROMPT_HOME_STRING "\033[31;1m~%s\033[0m > "

# define TAKE_INPUT_EXIT_CALLED 2
# define TAKE_INPUT_READLINE_FAILED 1
# define TAKE_INPUT_SUCCESS 0
# define RUNTIME_LOOP_EXIT 0
# define RUNTIME_LOOP_CRASH 1
# define DISPLAY_PROMPT_CWD_FAIL 1
# define DISPLAY_PROMPT_SUCCESS 0

# include <table.h>

extern t_vector	g_running_processes;
extern int		g_program_status;

int				runtime_loop(t_table *env);
int				display_prompt(t_table *env);
int				read_char(char *out);
int				read_line(
				char **line,
				int eof_matters);
int				take_input(char **input);

#endif
