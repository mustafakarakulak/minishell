/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:12 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/27 18:16:43 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	all_free(t_env *data)
{
	int	i;

	i = -1;
	free(data->line);
	while (data->prompt[++i])
		free(data->prompt[i]);
	free(data->prompt);
}
