/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:20:01 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/04 15:24:42 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_command_checker(char *str, t_env *data)
{
	char	**line;

	data->count = 0;
	line = ft_split(str, 32);
	while (line[data->count])
		data->count++;
	return (line);
}
