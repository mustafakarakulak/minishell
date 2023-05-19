/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:05:14 by mustafakara       #+#    #+#             */
/*   Updated: 2023/05/19 21:10:17 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    check_way(t_env *data)
{
    t_arg   *temp;

    temp = data->t_arg;
    while (temp)
    {
        if (temp->type == WORD)
            //
        else if (temp->type == INPUT_RDR)
            //
        else if (temp->type == OUTPUT_RDR)
            //     
        else if (temp->type == DOUBLE_INPUT_RDR)
            //
        else if (temp->type == DOUBLE_OUTPUT_RDR)
            //
        else if (temp->type == PIPE)
            //
        else
            return (0);
        return (1);
    }
}