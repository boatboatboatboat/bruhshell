/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:19 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:19 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdlib.h>

void	vector_destroy(t_vector *self)
{
	if (self->dtor)
		self->dtor(self);
	free(self->raw);
	self->raw = NULL;
	self->capacity = 0;
	self->size = 0;
	self->type_size = 0;
	self->dtor = NULL;
}
