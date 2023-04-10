/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:22:06 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/10 18:46:17 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_command_checker(char *str, t_env *data)
{
	char	**line;
	int		i;

	data->count = 0;
	i = 0;
	line = ft_split(str, ' ');
	while (line[i])
		i++;
	data->input = (char **)malloc(sizeof(char *) * i);
	while (i > 0)
	{
		data->input[data->count++] = ft_strdup(line[data->count]);
		i--;
	}
	return (line);
}

void	error_checker(t_env *data, char **env)
{
	if (ft_strcmp(data->input[0], "history\n"))
	{
		printf("history\n");
	}
	//if (ft_strcmp(data->input[0], "echo") == 0)
	//	ft_echo(data);
	//else if (ft_strcmp(data->input[0], "cd") == 0)
	//	ft_cd(data);
	//else if (ft_strcmp(data->input[0], "pwd") == 0)
	//	ft_pwd(data);
	//else if (ft_strcmp(data->input[0], "export") == 0)
	//	ft_export(data, env);
	//else if (ft_strcmp(data->input[0], "unset") == 0)
	//	ft_unset(data, env);
	//else if (ft_strcmp(data->input[0], "env") == 0)
	//	ft_env(data, env);
	//else if (ft_strcmp(data->input[0], "exit") == 0)
	//	ft_exit(data);
	//else
	//	ft_exec(data, env);
}