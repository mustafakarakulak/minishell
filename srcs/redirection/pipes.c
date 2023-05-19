/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:38:04 by mustafakara       #+#    #+#             */
/*   Updated: 2023/05/18 20:50:26 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    *ft_pipe(t_env *data)
{
    t_arg *temp;

    temp = data->t_arg;
    while (temp)
    {
        if (ft_strcmp(temp->arg, "|") == 0)
        {
            data->pipe = 1;
            return (temp);
        }
        temp = temp->next;
    }
}