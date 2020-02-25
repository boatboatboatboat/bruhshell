/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:19:59 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 18:20:45 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_new(
	t_vector *self,
	size_t type_size)
{
	return (vector_with_capacity(self, type_size, 0));
}
