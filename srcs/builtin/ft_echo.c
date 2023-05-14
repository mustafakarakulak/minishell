/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:59 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/14 20:54:00 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo_param_checker(char *str)
{
	int	i;

	i = 2;
	if (!str[0] || str[0] != '-')
		return (0);
	if (!str[1] || str[1] != 'n')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
		
}

void	ft_echo(t_env *data)
{
	t_arg	*temp;

	temp = data->t_arg->next;
	if (!temp)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	if (ft_echo_param_checker(temp->arg))
		temp = temp->next;
	while (temp)
	{
		ft_putstr_fd(temp->arg, 1);
		if (temp->next)
			ft_putstr_fd(" ", 1);
		temp = temp->next;
	}
	if (ft_echo_param_checker(data->t_arg->next->arg) == 0)
		ft_putstr_fd("\n", 1);
}
