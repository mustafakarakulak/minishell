/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/04 19:09:59 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

int	builtin(t_env *data, char **args, char **envp)
{
	if (ft_strcmp(args[0], "echo"))
		ft_echo(args);
	else if (ft_strcmp(args[0], "cd"))
		ft_cd(args);
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
