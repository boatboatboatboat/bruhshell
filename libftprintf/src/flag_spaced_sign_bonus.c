/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_spaced_sign_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:46 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:46 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flag_spaced_sign(t_flags *flag, char **token, va_list *argp)
{
	(void)argp;
	if (flag->forced_sign != '+')
		flag->forced_sign = ' ';
	(*token)++;
}
