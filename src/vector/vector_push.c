/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_push.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:24 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:24 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <libft.h>

t_bool	vector_push(
		t_vector *self,
		void *value)
{
	size_t	min_capacity;

	min_capacity = self->capacity ? self->capacity : 4;
	if (self->size >= self->capacity)
		if (!vector_resize(self, min_capacity * 2))
			return (false);
	ft_memcpy(&self->raw[self->size * self->type_size],
			value, self->type_size);
	self->size += 1;
	return (true);
}
