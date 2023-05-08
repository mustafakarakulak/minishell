/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:40:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/08 23:53:00 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env_counter(t_env *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
		i++;
	return (i);
}

int	env_founder(char *envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i] == name[i])
		i++;
	if (envp[i] == '=')
		return (1);
	else
		return (0);
}

int	ft_path_founder(char **envp, char *name, int len)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (env_founder(envp[i], name) == 1)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_unset(t_env *data)
{
	int	i;
	int	env_c;
	int	arg_c;

	arg_c = 1;
	if (!data->prompt[arg_c])
		return ;
	env_c = ft_env_counter(data);
	while (data->prompt[arg_c])
	{
		i = ft_path_founder(data->envp, data->prompt[arg_c],
				ft_strlen(data->prompt[arg_c]));
		if (i != -1)
			ft_delenv(data, i, env_c);
		arg_c++;
	}
}
