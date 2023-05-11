/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:59 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/11 21:49:10 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(t_env *data)
{
	t_arg	*temp;

	temp = data->t_arg->next;
	printf("temp->arg = %s\n", temp->arg);
	if (ft_strcmp(temp->arg, "-n") == 1 && temp->next)
	{
		temp = temp->next;
	}
	while (temp->arg)
	{
		ft_putstr_fd(temp->arg, 1);
		if (temp->next)
			ft_putstr_fd(" ", 1);
		temp = temp->next;
	}
	if (ft_strcmp(data->t_arg->next->arg, "-n") == 0)
		ft_putstr_fd("\n", 1);
}
