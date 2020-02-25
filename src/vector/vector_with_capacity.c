/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_with_capacity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:15:26 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 18:20:45 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdlib.h>

t_bool	vector_with_capacity(
	t_vector *self,
	size_t type_size,
	size_t capacity)
{
	if (capacity > 0)
		self->raw = malloc(type_size * capacity);
	else
		self->raw = NULL;
	if (capacity > 0 && self->raw == NULL)
		return (false);
	self->capacity = capacity;
	self->size = 0;
	self->type_size = type_size;
	return (true);
}
