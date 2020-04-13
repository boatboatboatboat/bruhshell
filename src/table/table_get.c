/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table_get.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:30 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:30 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>
#include <libft.h>

char			*table_get(
		t_table *self,
		char *key)
{
	t_table_entry	*entry;

	entry = table_get_entry(self, key);
	if (entry)
		return (entry->value);
	return (NULL);
}

t_table_entry	*table_get_entry(
		t_table *self,
		char *key)
{
	size_t			idx;
	t_table_entry	*entry;

	idx = 0;
	while (idx < self->size)
	{
		if (vector_getr(self, idx, (void **)&entry))
			if (entry != NULL && ft_strncmp(entry->key, key, ULL_MAX) == 0)
				return (entry);
		idx += 1;
	}
	return (NULL);
}
