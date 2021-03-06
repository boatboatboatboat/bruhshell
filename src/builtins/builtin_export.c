/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_export.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:58:57 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:58:57 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>
#include <stdlib.h>

static t_bool	is_valid_identifier(char *str)
{
	size_t	idx;

	if (str == NULL)
		return (false);
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		return (false);
	idx = 1;
	while (str[idx] != '\0')
	{
		if (!(ft_isalnum(str[idx]) || str[idx] == '_'))
			return (false);
		idx += 1;
	}
	return (true);
}

static int		free_pair(
		void *a,
		void *b)
{
	if (b != NULL)
	{
		free(a);
		free(b);
	}
	return (1);
}

static t_bool	try_set(
		char *str,
		t_table *env,
		char *var[2])
{
	size_t	location;
	size_t	length;

	location = 0;
	while (str[location] != '=' && str[location] != '\0')
		location += 1;
	if (str[location] == '\0')
	{
		var[0] = str;
		return (is_valid_identifier(str) ? 0 : 2);
	}
	length = ft_strlen(str);
	var[0] = ft_substr(str, 0, location);
	var[1] = ft_substr(str, location + 1, location - length);
	if (var[0] == NULL || var[1] == NULL)
		return (1);
	if (!is_valid_identifier(var[0]))
		return (2);
	if (!table_insert(env, var[0], var[1]))
		return (1);
	return (0);
}

static void		throw_identifier_error(char *ident)
{
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(ident, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

int				export_main(
		int argc,
		char **argv,
		t_table *env)
{
	int		idx;
	int		errored;
	int		res;
	char	*var[2];

	idx = 0;
	argc -= 1;
	errored = 0;
	ft_bzero(var, sizeof(char *[2]));
	if (argc == 0)
		return (do_useless_thing(env));
	while (idx < argc)
	{
		idx += 1;
		res = try_set(argv[idx], env, var);
		if (res == 1)
			ft_perror("failed to set variable");
		if (res == 2)
			throw_identifier_error(var[0]);
		if (res != 0)
			free_pair(var[0], var[1]);
		errored = errored || res != 0;
	}
	return (errored);
}
