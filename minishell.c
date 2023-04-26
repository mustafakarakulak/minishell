/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/26 14:55:49 by mkarakul         ###   ########.fr       */
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
	{
		wait(&status);
	}
}

void	control_shell(char **envp, t_env *data)
{
	char	*line;
	char	**args;
	int		status;

	while (1)
	{
		printf("\033[31m╭─%s@\033[0m\033[31mminishell$\n╰─$ \033[0m",
			get_username(envp));
		line = readline("");
		add_history(line);
		args = ft_command_checker(line, data);
		if (!args[0])
			continue ;
		if (ft_strcmp(args[0], "exit"))
			break ;
		if (!builtin(data, args, envp))
			exec_shell(data, args, status, envp);
		free(line);
		free(args);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*data;

	data = (t_env *)malloc(sizeof(t_env));
	control_shell(env, data);
	free(data);
	return (0);
}
