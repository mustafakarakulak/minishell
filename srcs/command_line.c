/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:29:36 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/21 15:47:56 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_command_line(t_env *data)
{
	t_arg	*temp;
	int		i;

	i = 0;
	temp = data->t_arg;
	data->command = malloc(sizeof(char *) * 100000);
	while (temp)
	{
		data->command[i] = temp->arg;
		i++;
		if (temp)
			temp = temp->next;
	}
	data->temp_list = temp;
}
