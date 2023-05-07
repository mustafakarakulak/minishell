/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:41:07 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/07 16:49:31 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_export(t_env *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(data->envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return ;
}
