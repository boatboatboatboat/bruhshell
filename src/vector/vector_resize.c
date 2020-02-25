/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:23:06 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 18:26:48 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_resize(
		t_vector *self,
		size_t capacity)
{
	if (capacity <= self->capacity)
		return (false);
	self->raw = ft_realloc(self->raw, self->size, capacity);
	if (self->raw == NULL)
		return (false);
	self->capacity = capacity;
	return (true);
}
