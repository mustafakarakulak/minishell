/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:17:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/15 02:06:14 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	control_bin2(t_arg *temp, char *path, int j, char *dir)
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
		tmp = ft_strjoin(tmp, temp->arg);
		if (access(tmp, F_OK) == 0)
		{
			temp->arg = tmp;
			free(dir);
			return (1);
		}
		free(dir);
		free(tmp);
		i = j + 1;
	}
	return (0);
}

int	control_bin(t_env *data)
{
	int		i;
	int		j;
	char	*path;
	char	*dir;
	t_arg	*temp;

	temp = data->t_arg;
	i = 0;
	if (ft_strncmp(temp->arg, "./", 2) == 0)
		return (1);
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
		{
			path = data->envp[i] + 5;
			break ;
		}
		i++;
	}
	i = 0;
	if (control_bin2(temp, path, j, dir))
		return (1);
	return (0);
}

void	ft_execve(t_env *data)
{
	if (control_bin(data))
		execve(data->t_arg->arg, data->command, data->envp);
	else
	{
		printf("minishell: %s: command not found\n", data->t_arg->arg);
		exit (1);
	}
}
