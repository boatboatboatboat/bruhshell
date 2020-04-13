/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_passedwidth.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:46 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:46 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printf.h"

void		flag_passedwidth(t_flags *flag, char **token, va_list *argp)
{
	int		width;

	width = va_arg(*argp, int);
	if (width < 0)
	{
		flag->flags |= FLAG_LEFT_JUSTIFY;
		width *= -1;
	}
	flag->flags |= FLAG_WIDTHARG_SET;
	flag->width = width;
	(*token)++;
}
