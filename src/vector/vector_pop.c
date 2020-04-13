/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_pop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:23 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:23 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_pop(
		t_vector *self,
		void *output)
{
	t_bool	result;

	if (self->size == 0)
		return (false);
	result = vector_get(self, self->size - 1, output);
	if (result)
		self->size -= 1;
	return (result);
}
