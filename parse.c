/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:07:39 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/25 16:24:55 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_key(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	temp = ft_substr(str, 0, i);
	return (temp);
}

char	*get_env_value(char *str, char *key)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '=')
		temp = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (ft_strcmp(key, "OLDPWD") == 0)
		return (NULL);
	return (temp);
}

t_env	*make_env_node(char *key, char *value)
{
	t_env	*data;

	data = (t_env *)malloc(sizeof(t_env));
	if (!data)
		return (NULL);
	data->key = NULL;
	data->value = NULL;
	data->key = ft_strdup(key);
	data->value = ft_strdup(value);
	return (data);
}

t_env	*parse_env(t_env *data, char **envp)
{
	t_env	*new;
	t_env	*temp;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	new = ft_lstnew(make_env_node("0", "minishell"));
	ft_lstadd_back(&data, new);
	while (envp[i])
	{
		key = get_env_key(envp[i]);
		value = get_env_value(envp[i], key);
		temp = make_env_node(key, value);
		new = ft_lstnew(temp);
		ft_lstadd_back(&data, new);
		free(key);
		free(value);
		i++;
	}
	return (data);
}
