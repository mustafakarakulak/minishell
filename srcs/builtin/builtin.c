/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/20 19:04:31 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin(t_env *data)
{
	if (ft_strcmp(data->t_arg->arg, "echo"))
		ft_echo(data);
	else if (ft_strcmp(data->t_arg->arg, "cd"))
		ft_cd(data);
	else if (ft_strcmp(data->t_arg->arg, "pwd"))
		ft_pwd(data);
	else if (ft_strcmp(data->t_arg->arg, "export"))
		ft_export(data);
	else if (ft_strcmp(data->t_arg->arg, "unset"))
		ft_unset(data);
	else if (ft_strcmp(data->t_arg->arg, "env"))
		ft_env(data);
	else
		return (-1);
	return (0);
}
