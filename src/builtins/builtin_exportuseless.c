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

#include <ft_printf.h>
#include <builtin.h>

static void	print_declare(char *key, char *str)
{
	ft_printf("declare -x %s=\"", key);
	while (*str != '\0')
	{
		ft_printf(*str == '"' ? "\\%c" : "%c", *str);
		str += 1;
	}
	ft_printf("\"\n");
}

int			do_useless_thing(t_table *env)
{
	size_t			idx;
	t_table_entry	entry;

	idx = 0;
	while (idx < env->size)
	{
		if (vector_get(env, idx, &entry) && entry.value != NULL)
			print_declare(entry.key, entry.value);
		idx += 1;
	}
	return (0);
}
