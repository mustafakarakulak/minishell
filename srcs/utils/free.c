/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:12 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/12 15:28:21 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	all_free(t_env *data)
{
	free(data->line);
	while (data->t_arg)
	{
		free(data->t_arg->arg);
		data->t_arg = data->t_arg->next;
	}
}
