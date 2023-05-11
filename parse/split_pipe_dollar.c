/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:50:42 by serif             #+#    #+#             */
/*   Updated: 2023/05/11 18:15:32 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int is_pipe(char *s)
{
	if (*s == '|')
		return (1);
	return (0);	
}

void	split_by_pipe(t_arg **prompt)
{
	t_arg *iter;

	iter = *prompt;
	while (iter)
	{
		if(handle_character(&iter, &is_pipe))
			iter = iter->next;
		else
			iter = iter->next;
		if (!iter)
			break;
		if (!iter->next)
		{
			handle_character(&iter, &is_pipe);
			iter = iter->next;
		}
	}
}
