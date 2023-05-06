/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:33 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/06 18:36:36 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cd(char **execute)
{
	if (execute[1] && ft_strcmp(execute[1], "~") == 0)
	{
		if (chdir(execute[1]))
			perror("minishell ");
	}
	else if (chdir(getenv("HOME")))
		perror("minishell ");
}
