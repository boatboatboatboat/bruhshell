/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:20 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:20 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <libft.h>

t_bool	vector_get(
		t_vector *self,
		size_t index,
		void *value)
{
	if (index >= self->size)
		return (false);
	ft_memcpy(value, &(self->raw[self->type_size * index]), self->type_size);
	return (true);
}
