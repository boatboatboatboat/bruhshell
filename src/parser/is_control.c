/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_control.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:45 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:45 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool		is_control(char c)
{
	return (c == '>' || c == '<' || c == '|' || c == ' ');
}

t_bool		is_not_control(char c)
{
	return (!is_control(c));
}
