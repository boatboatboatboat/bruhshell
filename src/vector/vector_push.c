/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:28:51 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 18:31:55 by dpattij          ###   ########.fr       */
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
