/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table_insert.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:31 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:31 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>
#include <stdlib.h>

t_bool			table_insert(
		t_table *self,
		char *key,
		char *value)
{
	t_table_entry	pair;
	t_table_entry	*maybe;

	maybe = table_get_entry(self, key);
	if (maybe != NULL)
	{
		free(maybe->key);
		free(maybe->value);
		maybe->key = key;
		maybe->value = value;
		return (true);
	}
	else
	{
		pair.key = key;
		pair.value = value;
	}
	return (vector_push(self, &pair));
}
