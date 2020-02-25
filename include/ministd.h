/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ministd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:21:38 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 17:46:36 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTD_H
# define MINISTD_H

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

char	*ft_realloc(
		char *ptr,
		int ocapacity,
		int capacity);

#endif
