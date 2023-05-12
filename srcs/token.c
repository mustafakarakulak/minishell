/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:29:36 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/12 22:14:59 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_token(t_env *data)
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
}
