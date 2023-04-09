/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/09 14:19:12 by mkarakul         ###   ########.fr       */
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

int	main(int ac, char **av, char **env)
{
	t_env	*data;
	char	*line;

	data = (t_env *)malloc(sizeof(t_env));
	data->username = get_username(env);
	while (1)
	{
		printf("%s@", data->username);
		line = readline("minishell$ ");
		add_history(line);
		write_history("/Users/mkarakul/Desktop/projemini/log/.bash_history");
		if (ft_strcmp(line, "exit\n"))
			break ;
		ft_command_checker(line, data);
	}
	return (0);
}
