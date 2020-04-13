/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_perror.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:34 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:34 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errno.h>
#include <string.h>
#include <zconf.h>

void	ft_perror(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}
