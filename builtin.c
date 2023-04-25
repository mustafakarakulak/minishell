/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/25 21:20:29 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_getenv(t_env *data, char *name, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], name, ft_strlen(name)) == 0)
			return (args[i] + ft_strlen(name) + 1);
		i++;
	}
	return (NULL);
}

void	ft_echo(t_env *data, char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	ft_cd(t_env *data, char **args)
{
	char	*path;

	if (args[1] == NULL)
	{
		path = ft_getenv(data, "HOME", args);
		if (path == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return ;
		}
	}
	else
		path = args[1];
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
	}
}

void	ft_pwd(t_env *data, char **args)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}

void	ft_env(t_env *data, char **args, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int	builtin(t_env *data, char **args, char **envp)
{
	if (ft_strcmp(args[0], "echo"))
		ft_echo(data, args);
	else if (ft_strcmp(args[0], "cd"))
		ft_cd(data, args);
	else if (ft_strcmp(args[0], "pwd"))
		ft_pwd(data, args);
	//else if (ft_strcmp(args[0], "export") == 0)
	//	ft_export(data, args);
	//else if (ft_strcmp(args[0], "unset"))
	//	ft_unset(data, args);
	else if (ft_strcmp(args[0], "env"))
		ft_env(data, args, envp);
	else
		return (0);
	return (1);
}
