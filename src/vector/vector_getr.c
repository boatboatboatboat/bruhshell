/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_getr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:21 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:21 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_getr(
		t_vector *self,
		size_t index,
		void **value)
{
	if (index >= self->size)
		return (false);
	*value = &(self->raw[self->type_size * index]);
	return (true);
}
