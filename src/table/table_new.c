/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:31 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:31 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>
#include <stdlib.h>

static void	cleanup_table(t_table *self)
{
	t_table_entry	entry;

	while (vector_pop(self, &entry))
	{
		free(entry.key);
		free(entry.value);
	}
}

t_bool		table_new(t_table *self)
{
	return (vector_new_dtor(self, sizeof(t_table_entry), cleanup_table));
}
