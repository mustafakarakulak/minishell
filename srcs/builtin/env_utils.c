/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:32 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/04 15:25:07 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_env *data, char **args)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}

void	*ft_addenv(t_env *data, char *name, char **args)
{
	int		i;
	char	*tmp;

	i = 0;
	while (args[i])
		i++;
	tmp = malloc(sizeof(char) * (ft_strlen(name) + 1));
	ft_strcpy(tmp, name);
	args[i] = tmp;
	args[i + 1] = NULL;
	return (args[i]);
}

void	*ft_delenv(t_env *data, char *name, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], name, ft_strlen(name)) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			return (args[i]);
		}
		i++;
	}
	return (NULL);
}

void	*ft_getenv(t_env *data, char *name, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], name, ft_strlen(name)) == 0)
			return (args[i] + ft_strlen(name) + 1);
		i++;
	}
	return (NULL);
}

void	ft_env(t_env *data, char **args, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
