/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_leftjustify.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:45 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:45 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		flag_leftjustify(t_flags *flag, char **token, va_list *argp)
{
	(void)argp;
	flag->flags |= FLAG_LEFT_JUSTIFY;
	(*token)++;
}
