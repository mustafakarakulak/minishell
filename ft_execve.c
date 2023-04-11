/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:17:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/11 18:17:17 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int cd(const char *path)
{
	DIR *dir;
	struct dirent *entry;
	char buf[1024];
	int ret = -1;

	if ((dir = opendir(path)) == NULL)
	{
		perror(path);
		return -1;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR)
		{
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;
			if (strcmp(entry->d_name, path) == 0)
			{
				snprintf(buf, sizeof(buf), "%s/%s", path, entry->d_name);
				ret = chdir(buf);
				break;
			}
		}
	}

	closedir(dir);
	return ret;
}

int	control_bin(t_env *data, char **args, char **envp)
{
	int i, j;
	char	*path, *dir, *tmp;

	if (ft_strcmp(args[0], "cd") == 0)
	{
		if (args[1])
			cd(args[1]);
		else
			perror("allah");
		return (0);
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	i = 0;
	while (path[i])
	{
		j = i;
		while (path[j] && path[j] != ':')
			j++;
		dir = ft_substr(path, i, j - i);
		tmp = ft_strjoin(dir, "/");
		tmp = ft_strjoin(tmp, args[0]);
		if (access(tmp, F_OK) == 0)
		{
			args[0] = tmp;
			free(dir);
			return (1);
		}
		free(dir);
		free(tmp);
		i = j + 1;
	}
	return (0);
}

void	ft_execve(t_env *data, char **args, char **envp)
{
	if (control_bin(data, args, envp))
		execve(args[0], args, envp);
	else
		perror("miniShell");
}
