/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/26 22:09:10 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_username(char **envp)
{
	char	*username;
	int		i;

	username = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "USER=", 5) == 0)
		{
			username = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (username);
}

void	exec_shell(t_env *data, char **args, int status, char **envp)
{
	if (fork() == 0)
		ft_execve(data, args, envp);
	else
		wait(&status);
}

void	start(t_env *data)
{
	char	*line;
	int		status;
	int		i;

	while (1)
	{
		i = -1;
		printf("\033[31m╭─%s@\033[0m\033", get_username(data->envp));
		line = readline("[31mminishell$\n╰─$ \033[0m");
		add_history(line);
		data->line = ft_command_checker(line, data);
		if (!data->line[0])
			continue ;
		if (ft_strcmp(data->line[0], "exit"))
			break ;
		if (builtin(data, data->line, data->envp))
			exec_shell(data, data->line, status, data->envp);
		free (line);
		while (data->line[++i])
			free(data->line[i]);
		free(data->line);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*data;

	data = (t_env *)malloc(sizeof(t_env));
	data->envp = env;
	start(data);
	free(data->line);
	return (0);
}
