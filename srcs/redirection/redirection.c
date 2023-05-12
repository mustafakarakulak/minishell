/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:23:42 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/12 11:40:50 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
/*
void	*ft_pipe(t_env *data)
{
	int		fd[2];
	char	**cmd;

	cmd = ft_split(data->line, ' ');
	pipe(fd);
	if (fork() == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		ft_execve(data);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		ft_execve(data);
	}
	return (0);
}

void	*ft_redirection_out(t_env *data)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(data->line, ' ');
	fd = open(cmd[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve(data);
	return (0);
}

void	*ft_redirection_out_append(t_env *data)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(data->line, ' ');
	fd = open(cmd[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve(data);
	return (0);
}

void	*ft_redirection_in(t_env *data)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(data->line, ' ');
	fd = open(cmd[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	ft_execve(data);
	return (0);
}

void	*ft_redirection_in_append(t_env *data)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(data->line, ' ');
	fd = open(cmd[1], O_RDONLY | O_APPEND);
	dup2(fd, STDIN_FILENO);
	close(fd);
	ft_execve(data);
	return (0);
}

int	ft_redirection_control(t_env *data)
{
	if (ft_strcmp(data->prompt[0], ">"))
		ft_redirection_out(data);
	else if (ft_strcmp(data->line, ">>"))
		ft_redirection_out_append(data);
	else if (ft_strcmp(data->line, "<"))
		ft_redirection_in(data);
	else if (ft_strcmp(data->line, "<<"))
		ft_redirection_in_append(data);
	else if (ft_strcmp(data->line, "|"))
		ft_pipe(data);
	else
		return (1);
	return (0);
}
*/