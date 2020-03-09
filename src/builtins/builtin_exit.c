/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:26:13 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/31 23:17:15 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include <ministd.h>
#include <libft.h>

static t_bool	take_n(const char *str, unsigned char *out)
{
	*out = 0;
	while (*str != '\0' && ft_isdigit(*str))
	{
		*out = *out * 10 + *str - '0';
		str += 1;
	}
	if (*str != '\0')
		return (false);
	return (true);
}

int				exit_main(
		int argc,
		char **argv)
{
	unsigned char	code;

	ft_printf("exit\n");
	if (argc == 1)
		exit(0);
	if (!take_n(argv[1], &code))
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
	if (argc > 2)
		ft_putendl_fd("exit: too many arguments", 2);
	else if (argc == 2)
		exit(code);
	return (1);
}
