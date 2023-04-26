/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:20:01 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/26 14:22:28 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_command_checker(char *str, t_env *data)
{
	char	**line;
	int		i;

	data->count = 0;
	i = 0;
	line = ft_split(str, ' ');
	while (line[i])
		i++;
	data->input = (char **)malloc(sizeof(char *) * i);
	while (i > 0)
	{
		data->input[data->count++] = ft_strdup(line[data->count]);
		i--;
	}
	return (line);
}
