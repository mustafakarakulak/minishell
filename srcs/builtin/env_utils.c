/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:32 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/12 21:53:34 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_env *data)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}

char	**ft_addenv(t_env *data)
{
	int		i;
	char	**tmp;
	t_arg	*temp;

	temp = data->t_arg;
	temp = temp->next;
	i = 0;
	tmp = malloc(sizeof(char **) * 10000000);
	while (data->ex_path[i])
	{
		tmp[i] = data->ex_path[i];
		i++;
	}
	tmp[i] = temp->arg;
	data->ex_path = tmp;
	free(tmp);
	return (data->ex_path);
}

void	*ft_delenv(t_env *data, int i, int env_c)
{
	int		c;
	int		j;
	char	**tmp;

	c = 0;
	j = 0;
	tmp = malloc(sizeof(char **) * 1000);
	while (data->envp[j])
	{
		if (j == i)
			j++;
		tmp[c] = data->envp[j];
		c++;
		j++;
	}
	tmp[c] = NULL;
	data->envp = tmp;
	free(tmp);
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

void	ft_env(t_env *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		ft_putstr_fd(data->envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
