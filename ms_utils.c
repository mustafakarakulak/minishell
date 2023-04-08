/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:22:06 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/08 17:24:41 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_command_checker(char *str)
{
	if (ft_strcmp(str, "echo"))
		return (1);
	if (ft_strcmp(str, "history"))
	{
		
	}
}

