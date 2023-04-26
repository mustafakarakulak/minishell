/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/26 22:13:13 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_unset(t_env *data, char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		ft_delenv(data, args[i], data->envp);
		i++;
	}
}

void	ft_export(t_env *data, char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_getenv(data, args[i], data->envp) == NULL)
			ft_addenv(data, args[i], data->envp);
		i++;
	}
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

int	builtin(t_env *data, char **args, char **envp)
{
	if (ft_strcmp(args[0], "echo"))
		ft_echo(data, args);
	else if (ft_strcmp(args[0], "cd"))
		ft_cd(data, args);
	else if (ft_strcmp(args[0], "pwd"))
		ft_pwd(data, args);
	else if (ft_strcmp(args[0], "export"))
		ft_export(data, args);
	else if (ft_strcmp(args[0], "unset"))
		ft_unset(data, args);
	else if (ft_strcmp(args[0], "env"))
		ft_env(data, args, envp);
	else
		return (1);
	return (0);
}
