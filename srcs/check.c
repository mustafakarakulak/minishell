/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:05:14 by mustafakara       #+#    #+#             */
/*   Updated: 2023/05/25 20:43:56 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_way(t_env *data)
{
	t_arg	*temp;
	int		status;

	temp = data->t_arg;
	if (builtin(data) != -1)
		return (0);
	status = fork();
	if (temp && status == 0)
	{
		if (temp->type == WORD)
			exec_shell(data, status);
		else if (temp->type == INPUT_RDR)
			redirection_checker(data);
		else if (temp->type == OUTPUT_RDR)
			redirection_checker(data);
		else if (temp->type == DOUBLE_INPUT_RDR)
			redirection_checker(data);
		else if (temp->type == DOUBLE_OUTPUT_RDR)
			redirection_checker(data);
		exit (0);
		return (0);
	}
	else
		wait(&status);
}
