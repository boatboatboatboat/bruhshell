/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_exportuseless.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:08 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:08 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <table.h>

int		is_builtin(const char *name);
int		run_builtin(
		t_vector *args,
		t_vector *pipe_stack,
		const int pipes[2],
		t_table *env);

/*
** BUILTINS
*/

int		echo_main(
		int argc,
		char **argv);
int		exit_main(
		int argc,
		char **argv);
int		cd_main(
		int argc,
		char **argv,
		t_table *env);
int		pwd_main(
		int argc,
		char **argv);
int		env_main(
		int argc,
		char **argv,
		t_table *env);
int		unset_main(
		int argc,
		char **argv,
		t_table *env);
int		export_main(
		int argc,
		char **argv,
		t_table *env);
int		do_useless_thing(t_table *env);

#endif
