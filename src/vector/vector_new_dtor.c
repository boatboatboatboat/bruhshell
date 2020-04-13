/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_new_dtor.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:22 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:22 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_new_dtor(
		t_vector *self,
		size_t type_size,
		void (*dtor)(struct s_vector *self))
{
	return (vector_with_capacity_dtor(self, type_size, 0, dtor));
}
