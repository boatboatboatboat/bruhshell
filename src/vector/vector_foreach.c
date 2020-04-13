/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_foreach.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:20 by bruh           #+#    #+#                */
/*   Updated: 2020/04/13 21:36:20 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

int		vector_foreachc(
		t_vector *self,
		int (*f)(void *, void *),
		void *capture)
{
	size_t	idx;
	void	*ref;

	idx = 0;
	while (idx < self->size)
	{
		(void)vector_getr(self, idx, &ref);
		if (!f(ref, capture))
			return (0);
		idx += 1;
	}
	return (1);
}

int		vector_foreach(
		t_vector *self,
		int (*f)(void *))
{
	size_t	idx;
	void	*ref;

	idx = 0;
	while (idx < self->size)
	{
		(void)vector_getr(self, idx, &ref);
		if (!f(ref))
			return (0);
		idx += 1;
	}
	return (1);
}
