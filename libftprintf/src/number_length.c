/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number_length.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 22:04:54 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 22:04:54 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		number_length(long n, unsigned int base)
{
	int	length;

	length = n <= 0;
	while (n != 0)
	{
		length += 1;
		n /= base;
	}
	return (length);
}

int		number_length_u(unsigned long n, unsigned int base)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length += 1;
		n /= base;
	}
	return (length);
}
