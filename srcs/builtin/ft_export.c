/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:41:07 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/10 18:00:21 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*ft_export_path(t_env *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (data->ex_path[i])
	{
		j = 0;
		while (data->ex_path[i][j] != '=')
			j++;
		tmp = ft_substr(data->ex_path[i], 0, j);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("\n", 1);
		free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_export(t_env *data)
{
	if (!data->prompt[1] || ft_strcmp(data->prompt[1], "-p") == 1)
		ft_export_path(data);
	else
		ft_addenv(data);
}
