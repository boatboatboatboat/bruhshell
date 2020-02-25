/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:33:59 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 18:34:18 by dpattij          ###   ########.fr       */
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
