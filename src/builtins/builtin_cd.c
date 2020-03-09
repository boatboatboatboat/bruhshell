/* ************************************************************************** */
/*                                                                            */
/*   Project: memeshell420                                ::::::::            */
/*   Members: dpattij, tuperera                         :+:    :+:            */
/*   Copyright: 2020                                   +:+                    */
/*                                                    +#+                     */
/*                                                   +#+                      */
/*                                                  #+#    #+#                */
/*   while (!(succeed = try()));                   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ministd.h>
#include <libft.h>

int	cd_main(
		int argc,
		char **argv)
{
	if (argc > 1 && chdir(argv[1]) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_perror(argv[1]);
		return (1);
	}
	return (0);
}
