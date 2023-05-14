/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:23:42 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/15 02:08:08 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    *pipe(t_env *data)
{
    int     fd[2];
    int     pid;
    int     status;

    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        dup2(fd[1], 1);
        close(fd[0]);
        ft_execve(data);
    }
    else
    {
        dup2(fd[0], 0);
        close(fd[1]);
        wait(&status);
    }
    return (NULL);
}

void    *redirection(t_env *data)
{
    int     fd;
    int     pid;
    int     status;

    fd = open("file.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    pid = fork();
    if (pid == 0)
    {
        dup2(fd, 1);
        ft_execve(data);
    }
    else
        wait(&status);
    return (NULL);
}
