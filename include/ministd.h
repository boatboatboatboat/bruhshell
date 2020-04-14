/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_exportuseless.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:08 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:08 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTD_H
# define MINISTD_H

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

char	*ft_realloc(
		char *ptr,
		size_t ocapacity,
		size_t capacity);
void	ft_perror(char *str);

#endif
