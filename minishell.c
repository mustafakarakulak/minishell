/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/11 16:13:06 by mkarakul         ###   ########.fr       */
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
	{
		if (ft_strcmp(args[0], "ls"))
			execve("/bin/ls", args, NULL);
		else if (ft_strcmp(args[0], "cat"))
		{
			read_cat(args[1]);
			exit(1);
		}
		else if (ft_strcmp(args[0], "clear"))
			clear_screen();
		execve(args[0], args, envp);
		perror("miniShell");
		exit(1);
	}
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
		printf("\033[31m╭─%s@\033[0m", get_username(envp));
		line = readline("\033[31mminishell$\n╰─$ \033[0m");
		add_history(line);
		args = ft_command_checker(line, data);
		if (!args[0])
			continue ;
		if (ft_strcmp(args[0], "exit"))
			break ;
		exec_shell(data, args, status, envp);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*data;

	data = (t_env *)malloc(sizeof(t_env));
	control_shell(env, data);
	return (0);
}
