/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_groupedby1k_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:43 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:43 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flag_groupedby1k(t_flags *flag, char **token, va_list *argp)
{
	(void)argp;
	flag->flags |= FLAG_GROUPEDBY1K;
	(*token)++;
}
