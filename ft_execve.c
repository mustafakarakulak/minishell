/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:17:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/26 21:07:00 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	control_bin2(char **args, char *path, int j, char *dir)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
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

int	control_bin(t_env *data, char **args, char **envp)
{
	int		i;
	int		j;
	char	*path;
	char	*dir;

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
	if (control_bin2(args, path, j, dir))
		return (1);
	return (0);
}

void	ft_execve(t_env *data, char **args, char **envp)
{
	if (control_bin(data, args, envp))
		execve(args[0], args, envp);
	else
	{
		printf("minishell: %s: command not found\n", args[0]);
		exit (1);
	}
}
