/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/09 20:41:51 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_username(char **envp)
{
	char *username = NULL;
	int i;

	i = 0;

	while (envp[i])
	{
		if (ft_strncmp(envp[i], "USER=", 5) == 0)
		{
			username = envp[i] + 5;
			break;
		}
		i++;
	}
	return (username);
}

void	exec_shell(char **envp, t_env *data)
{
	char	*line;
	char	**args;
	int		status;
	
	while (1)
	{
		printf("\033[32m╭─%s@\033[0m", get_username(envp));
		line = readline("\033[32mminishell$\n╰─$ \033[0m");
		add_history(line);
		//write_history("/Users/mkarakul/Desktop/projemini/log/.bash_history");
		args = ft_command_checker(line, data);
		if (!args[0])
			continue ;
		if (ft_strcmp(args[0], "exit\n"))
			break ;
		error_checker(data, envp);
		if (fork() == 0)
		{
			execve(args[0], args, envp);
			perror("miniShell");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*data;

	data = (t_env *)malloc(sizeof(t_env));
	exec_shell(env, data);
	return (0);
}
