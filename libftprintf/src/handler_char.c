/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handler_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:49 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:49 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	padding(t_size length, char padder)
{
	t_size	idx;

	idx = 1;
	while (idx < length)
	{
		ft_putchar_fd(padder, 1);
		idx += 1;
	}
}

int			handler_char(t_flags flag, va_list *argp, t_size *written)
{
	char	arg;

	*written += flag.width > 1 ? flag.width : 1;
	arg = (char)va_arg(*argp, int);
	if (flag.flags & FLAG_LEFT_JUSTIFY)
	{
		ft_putchar_fd(arg, 1);
		padding(flag.width, ' ');
	}
	else
	{
		padding(flag.width, flag.flags & FLAG_ZERO_PADDING ? '0' : ' ');
		ft_putchar_fd(arg, 1);
	}
	return (1);
}
