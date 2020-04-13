/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_with_capacity_dtor.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:27 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:27 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdlib.h>

t_bool	vector_with_capacity_dtor(
		t_vector *self,
		size_t type_size,
		size_t capacity,
		void (*dtor)(struct s_vector *self))
{
	if (!vector_with_capacity(self, type_size, capacity))
		return (false);
	self->dtor = dtor;
	return (true);
}
