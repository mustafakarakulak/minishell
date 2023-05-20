/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/20 19:01:17 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	exec_shell(t_env *data, int status)
{
	if (fork() == 0)
	{
		data->child_check = -1;
		ft_execve(data);
	}
	else
		wait(&status);
}

void	start(t_env *data)
{
	t_arg	*temp;

	temp = NULL;
	while (1)
	{
		printf("\033[31m%s@\033[0m\033", get_username(data->envp));
		data->line = readline("[31mminishell-$> \033[0m");
		ft_parse(data);
		temp = data->t_arg;
		add_history(data->line);
		ft_command_line(data);
		if (!temp)
			continue ;
		if (ft_strcmp(temp->arg, "exit"))
			exit (0);
		check_way(data);
		data->child_check = 0;
		all_free(data);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*data;

	data = (t_env *)malloc(sizeof(t_env));
	data->envp = env;
	data->ex_path = data->envp;
	data->child_check = 0;
	start(data);
	return (0);
}
