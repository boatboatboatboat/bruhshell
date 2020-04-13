/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_resize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:25 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:25 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_resize(
		t_vector *self,
		size_t capacity)
{
	char	*new;

	if (capacity <= self->capacity)
		return (false);
	new = ft_realloc(self->raw, self->size * self->type_size,
			capacity * self->type_size);
	if (new == NULL)
	{
		vector_destroy(self);
		return (false);
	}
	self->raw = new;
	self->capacity = capacity;
	return (true);
}
