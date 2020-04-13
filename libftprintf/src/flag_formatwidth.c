/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_formatwidth.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:44 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:44 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flag_formatwidth(t_flags *flag, char **token, va_list *argp)
{
	t_size	width;

	(void)argp;
	width = 0;
	while (ft_isdigit(**token))
	{
		width = 10 * width + (**token - '0');
		(*token)++;
	}
	flag->width = width;
}
