/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:59 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/04 19:21:34 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(char **input)
{
	int	i;

	i = 1;
	if (!input[1])
		return ;
	while (ft_strcmp(input[i], "-n") == 1 && input[i])
		i++;
	while (input[i])
	{
		ft_putstr_fd(input[i], 1);
		if (input[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!ft_strcmp(input[1], "-n"))
		ft_putstr_fd("\n", 1);
}
