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
#include <sys/errno.h>
#include <stdio.h>

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
	size_t			idx[2];
	t_table_entry	entry;
	char			**envir;

	envir = ft_calloc(env->size, sizeof(char *));
	ft_bzero(idx, sizeof(size_t) * 2);
	while (idx[0] < env->size)
	{
		if (vector_get(env, idx[0], &entry) && entry.value != NULL)
		{
			envir[idx[1]] = malloc(sizeof(char) * (ft_strlen(entry.key)
								+ ft_strlen(entry.value) + 2));
			if (envir[idx[1]] != NULL)
			{
				ft_strlcat(envir[idx[1]], entry.key, ft_strlen(envir[idx[1]])
				+ ft_strlen(entry.key) + 1);
				ft_strlcat(envir[idx[1]], "=", ft_strlen(envir[idx[1]]) + 2);
				ft_strlcat(envir[idx[1]], entry.value, ft_strlen(envir[idx[1]])
				+ ft_strlen(entry.value) + 1);
				printf("envir[%lu] = %s\n", idx, envir[idx[1]]);
				idx[1] += 1;
			}
		}
		idx[0] += 1;
	}
	return (envir);
}

static int	get_executable(char *path, char **envir, char *const *args)
{
	ft_strlcat(path, "/", ft_strlen(path) + 2);
	ft_strlcat(path, args[0], ft_strlen(args[0])
				+ ft_strlen(path) + 1);
	execve(path, (char **)args, envir);
	return (0);
}

int			switch_to_process(
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
			return (get_executable(paths[i], envir, args) ? errno : errno);
		free(paths[i]);
		i++;
	}
	free(paths);
	if (ft_strchr(args[0], '/') != NULL)
		return (execve(args[0], args, envir) ? errno : errno);
	return (ENOENT);
}
