/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:29:36 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 16:06:12 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_command_line(t_env *data)
{
	t_arg	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	temp = data->t_arg;
	data->command = malloc(sizeof(char *) * 100000);
	while (temp)
	{
		if (temp->type == OUTPUT_RDR)
		{
			data->redirection[j++] = temp->arg;
			temp = temp->next;
			data->redirection[j++] = temp->arg;
		}
		else
			data->command[i++] = temp->arg;
		temp = temp->next;
	}
}
