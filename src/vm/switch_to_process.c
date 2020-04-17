/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   switch_to_process.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruh <bruh@bruh.bruh>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:36:11 by bruh          #+#    #+#                 */
/*   Updated: 2020/04/13 21:36:11 by bruh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <libft.h>
#include <unistd.h>
#include <table.h>
#include <stdlib.h>

char		*check_dir(char **args, char *path)
{
	DIR				*dirp;
	struct dirent	*direntp;

	dirp = opendir(path);
	if (dirp == NULL)
		return (NULL);
	while ((direntp = readdir(dirp)) != NULL)
	{
		if (ft_strncmp(direntp->d_name, args[0],
			ft_strlen(direntp->d_name)) == 0)
		{
			closedir(dirp);
			return (path);
		}
	}
	closedir(dirp);
	return (NULL);
}

static char	**get_env(t_table *env)
{
	size_t			idx;
	t_table_entry	entry;
	char			**envir;

	envir = malloc(sizeof(char *) * env->size);
	idx = 0;
	while (idx < env->size)
	{
		if (vector_get(env, idx, &entry) && entry.value != NULL)
		{
			envir[idx] = malloc(sizeof(char) * (ft_strlen(entry.key)
								+ ft_strlen(entry.value) + 2));
			if (envir[idx] != NULL)
			{
				ft_strlcat(envir[idx], entry.key, ft_strlen(envir[idx])
				+ ft_strlen(entry.key) + 1);
				ft_strlcat(envir[idx], "=", ft_strlen(envir[idx]) + 2);
				ft_strlcat(envir[idx], entry.value, ft_strlen(envir[idx])
				+ ft_strlen(entry.value) + 1);
			}
		}
		idx += 1;
	}
	envir[idx] = NULL;
	return (envir);
}

static void	get_executable(char *path, char **envir, char *const *args)
{
	ft_strlcat(path, "/", ft_strlen(path) + 2);
	ft_strlcat(path, args[0], ft_strlen(args[0])
				+ ft_strlen(path) + 1);
	execve(path, (char **)args, envir);
}

void		switch_to_process(
			char *const *args,
			t_table *env)
{
	char		**envir;
	char		*path;
	char		**paths;
	char		*check;
	int			i;

	envir = get_env(env);
	path = table_get(env, "PATH");
	paths = ft_split(path, ':');
	i = 0;
	while (paths != NULL && paths[i])
	{
		check = check_dir((char **)args, paths[i]);
		if (check != NULL)
			get_executable(paths[i], envir, args);
		free(paths[i]);
		i++;
	}
	free(paths);
	if (ft_strchr(args[0], '/') != NULL)
		execve(args[0], args, envir);
}
