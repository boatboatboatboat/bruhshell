/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_doprecision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:42 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:42 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		flag_doprecision(t_flags *flag, char **token, va_list *argp)
{
	int		precision_arg;
	t_size	precision;

	precision = 0;
	precision_arg = 0;
	(*token)++;
	if (**token == '\0')
		return ;
	if (**token == '*')
	{
		(*token)++;
		precision_arg = va_arg(*argp, int);
		if (argp < 0)
			return ;
		flag->precision = (t_size)precision_arg;
	}
	flag->flags |= FLAG_PRECISION_SET;
	while (ft_isdigit(**token))
	{
		precision = 10 * precision + (**token - '0');
		(*token)++;
	}
	if (!precision_arg)
		flag->precision = precision;
}
