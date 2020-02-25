/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_getr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:34:43 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 18:35:01 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_getr(
		t_vector *self,
		size_t index,
		void **value)
{
	if (index >= self->size)
		return (false);
	*value = &(self->raw[self->type_size * index]);
	return (true);
}
