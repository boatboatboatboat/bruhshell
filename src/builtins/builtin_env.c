/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 06:50:04 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/31 23:17:15 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <ft_printf.h>

int	env_main(
	int argc,
	char **argv,
	t_table *env)
{
	size_t			idx;
	t_table_entry	entry;

	(void)argc;
	(void)argv;
	idx = 0;
	while (idx < env->size)
	{
		if (vector_get(env, idx, &entry))
			ft_printf("%s=%s\n", entry.key, entry.value);
		idx += 1;
	}
	return (0);
}
