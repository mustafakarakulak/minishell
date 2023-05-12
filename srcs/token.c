/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:29:36 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/12 18:17:53 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_token(t_env *data)
{
	t_arg	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(t_arg) * 1);
	temp = data->t_arg;
	data->command = malloc(sizeof(char *) * 4);
	while (temp->arg)
	{
		data->command[i] = temp->arg;
		i++;
		if (temp->next)
			temp = temp->next;
	}
}
