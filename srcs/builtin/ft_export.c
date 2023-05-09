/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:41:07 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/09 08:52:39 by mkarakul         ###   ########.fr       */
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
	while (data->envp[i])
	{
		j = 0;
		while (data->envp[i][j] != '=')
			j++;
		tmp = ft_substr(data->envp[i], 0, j);
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
