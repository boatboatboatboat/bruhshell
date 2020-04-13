/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:53 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:53 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <ft_printf.h>

int	env_main(
	int argc,
	char **argv,
	t_table *env)
{
	size_t			idx;
	t_table_entry	entry;

	(void)argc;
	(void)argv;
	idx = 0;
	while (idx < env->size)
	{
		if (vector_get(env, idx, &entry) && entry.value != NULL)
			ft_printf("%s=%s\n", entry.key, entry.value);
		idx += 1;
	}
	return (0);
}
