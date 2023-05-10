/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/10 17:44:45 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin(t_env *data, char **args, char **envp)
{
	if (ft_strcmp(args[0], "echo"))
		ft_echo(args);
	else if (ft_strcmp(args[0], "cd"))
		ft_cd(args);
	else if (ft_strcmp(args[0], "pwd"))
		ft_pwd(data, args);
	else if (ft_strcmp(args[0], "export"))
		ft_export(data);
	else if (ft_strcmp(args[0], "unset"))
		ft_unset(data);
	else if (ft_strcmp(args[0], "env"))
		ft_env(data);
	else
		return (1);
	return (0);
}
