/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:17:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 16:00:40 by mkarakul         ###   ########.fr       */
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
		else
			i++;
	}
	if (data->envp[i] == NULL)
		return (0);
	if (control_bin2(temp, path, j, dir))
		return (1);
	return (0);
}

void	ft_execve(t_env *data)
{
	t_arg	*temp;

	temp = data->t_arg;
	if (control_bin(data))
		execve(temp->arg, data->command, data->envp);
	else
	{
		perror("minishell");
		exit (0);
	}
}
