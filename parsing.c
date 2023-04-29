/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:26:30 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/29 17:09:22 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	found_parameter(t_env *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (data->prompt[i])
	{
		while (data->prompt[i][j])
		{
			if (data->prompt[i][j] == '-')
				while (data->prompt[i][++j] && data->prompt[i][j] != ' ')
					data->parameter = data->prompt[i][j + 1];
			j++;
		}
		if (data->prompt[i])
			j = 0;
		i++;
	}
}

void	found_args(t_env *data)
{

}

void	found_command(t_env *data)
{

}

void	parsing_line(t_env *data, char **envp)
{
	data->prompt = ft_command_checker(data->line, data);
	found_command(data);
	found_parameter(data);
	found_args(data);
}
