/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:22 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:22 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_new(
	t_vector *self,
	size_t type_size)
{
	return (vector_with_capacity(self, type_size, 0));
}
