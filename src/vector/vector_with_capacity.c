/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_with_capacity.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:26 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:26 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdlib.h>

t_bool	vector_with_capacity(
	t_vector *self,
	size_t type_size,
	size_t capacity)
{
	if (capacity > 0)
		self->raw = malloc(type_size * capacity);
	else
		self->raw = NULL;
	if (capacity > 0 && self->raw == NULL)
		return (false);
	self->capacity = capacity;
	self->size = 0;
	self->type_size = type_size;
	self->dtor = NULL;
	return (true);
}
