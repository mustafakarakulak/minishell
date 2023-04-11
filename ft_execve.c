/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:17:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/11 16:32:51 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	control_bin(t_env *data, char **args, char **envp)
{
	int		i;
	char	*path;
	char	*tmp;

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
		if (path[i] == ':')
		{
			tmp = ft_substr(path, 0, i);
			args[0] = ft_strjoin(tmp, args[0]);
			free(tmp);
			break ;
		}
		i++;
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
