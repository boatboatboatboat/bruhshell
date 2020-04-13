/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_string_quote.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:46 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:46 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool	is_string_quote(char c)
{
	return (c == STRING_SINGLE_QUOTE || c == STRING_DOUBLE_QUOTE);
}
