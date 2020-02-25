/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:15:02 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/25 20:02:22 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stddef.h>

# define CMD_SEPERATOR ';'
# define STRING_SINGLE_QUOTE '\''
# define STRING_DOUBLE_QUOTE '"'

typedef struct	s_string_slice
{
	char		*str;
	size_t		len;
}				t_string_slice;

typedef struct	s_parser_error
{
	char		expected;
	char		found;
	size_t		character;
}				t_parser_error;

typedef struct	s_parser_object
{
	t_string_slice	input;
}				t_parser_object;

typedef union	u_parser_result
{
	t_parser_error	err;
	t_parser_object	obj;
}				t_parser_result;

#endif
