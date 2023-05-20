/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:05:14 by mustafakara       #+#    #+#             */
/*   Updated: 2023/05/20 19:04:35 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_way(t_env *data)
{
	t_arg	*temp;
	int		status;

	temp = data->t_arg;
	while (temp)
	{
		if (temp->type == WORD)
		{
			if (builtin(data) == -1)
				exec_shell(data, status);
		}
		else if (temp->type == INPUT_RDR)
			redirection_checker(data);
		else if (temp->type == OUTPUT_RDR)
			redirection_checker(data);
		else if (temp->type == DOUBLE_INPUT_RDR)
			redirection_checker(data);
		else if (temp->type == DOUBLE_OUTPUT_RDR)
			redirection_checker(data);
		else if (temp->type == PIPE)
			pipe(data);
		else
			return (0);
		return (1);
	}
}
