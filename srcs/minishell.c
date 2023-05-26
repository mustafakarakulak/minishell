/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 15:56:57 by mkarakul         ###   ########.fr       */
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
	if (status == 0)
		ft_execve(data);
	else
		perror("minishell");
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
		if (!temp)
			continue ;
		if (ft_strcmp(temp->arg, "exit"))
		{
			write(1, "exit\n", 5);
			exit (0);
		}
		check_way(data);
		add_history(data->line);
		all_free(data);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*data;

	data = (t_env *)malloc(sizeof(t_env));
	data->envp = env;
	data->ex_path = data->envp;
	start(data);
	return (0);
}
