/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_always_sign_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:41 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:41 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flag_always_sign(t_flags *flag, char **token, va_list *argp)
{
	(void)argp;
	flag->forced_sign = '+';
	(*token)++;
}
