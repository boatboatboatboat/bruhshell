/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table_destroy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:29 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:29 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>

void	table_destroy(t_table *self)
{
	vector_destroy(self);
}
