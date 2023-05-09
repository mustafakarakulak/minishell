/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:23:42 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/09 03:07:32 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*ft_pipe(t_env *data, char *args)
{
	int		fd[2];
	char	**cmd;

	cmd = ft_split(args, ' ');
	pipe(fd);
	if (fork() == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		ft_execve(data, cmd, data->envp);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		ft_execve(data, cmd, data->envp);
	}
	return (0);
}

void	*ft_redirection_out(t_env *data, char *args)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(args, ' ');
	fd = open(cmd[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve(data, cmd, data->envp);
	return (0);
}

void	*ft_redirection_out_append(t_env *data, char *args)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(args, ' ');
	fd = open(cmd[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve(data, cmd, data->envp);
	return (0);
}

void	*ft_redirection_in(t_env *data, char *args)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(args, ' ');
	fd = open(cmd[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	ft_execve(data, cmd, data->envp);
	return (0);
}

void	*ft_redirection_in_append(t_env *data, char *args)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(args, ' ');
	fd = open(cmd[1], O_RDONLY | O_APPEND);
	dup2(fd, STDIN_FILENO);
	close(fd);
	ft_execve(data, cmd, data->envp);
	return (0);
}

void	*ft_redirection_control(t_env *data, char *args)
{
	if (ft_strcmp(args, ">"))
		ft_redirection_out(data, args);
	else if (ft_strcmp(args, ">>"))
		ft_redirection_out_append(data, args);
	else if (ft_strcmp(args, "<"))
		ft_redirection_in(data, args);
	else if (ft_strcmp(args, "<<"))
		ft_redirection_in_append(data, args);
	else if (ft_strcmp(args, "|"))
		ft_pipe(data, args);
	return (0);
}
