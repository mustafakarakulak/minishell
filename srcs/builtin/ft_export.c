/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:41:07 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/08 16:59:34 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_export(t_env *data)
{
	int	i;

	i = 0;
	if (!data->prompt[1] || ft_strcmp(data->prompt[1], "-p"))
	{
		while (data->envp[i])
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(data->envp[i], 1);
			ft_putstr_fd("\n", 1);
			i++;
		}
	}
	return ;
}
