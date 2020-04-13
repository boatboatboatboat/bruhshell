/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_alternative_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:40 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:40 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flag_alternative(t_flags *flag, char **token, va_list *argp)
{
	(void)argp;
	flag->flags |= FLAG_ALTERNATIVE;
	(*token)++;
}
