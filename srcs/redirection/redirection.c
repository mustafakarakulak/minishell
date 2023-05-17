/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:48:13 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/17 20:23:00 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*input_rdr(t_env *data)
{
	int		fd;
	t_arg	*temp;

	temp = data->t_arg;
	fd = open(temp->next->arg, O_RDONLY);
	if (fd < 0)
	{
		printf("minishell: %s: No such file or directory\n", temp->next->arg);
		return (NULL);
	}
	dup2(fd, 0);
	close(fd);
	return (NULL);
}

void	*output_rdr(t_env *data)
{
	int		fd;
	t_arg	*temp;

	temp = data->t_arg;
	fd = open(temp->next->arg, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		printf("minishell: %s: No such file or directory\n", temp->next->arg);
		return (NULL);
	}
	dup2(fd, 1);
	close(fd);
	return (NULL);
}

void	*double_input_rdr(t_env *data)
{
	int		fd;
	t_arg	*temp;

	temp = data->t_arg;
	fd = open(temp->next->arg, O_RDONLY);
	if (fd < 0)
	{
		printf("minishell: %s: No such file or directory\n", temp->next->arg);
		return (NULL);
	}
	dup2(fd, 0);
	close(fd);
	return (NULL);
}

void	*double_output_rdr(t_env *data)
{
	int		fd;
	t_arg	*temp;

	temp = data->t_arg;
	fd = open(temp->next->arg, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("minishell: %s: No such file or directory\n", temp->next->arg);
		return (NULL);
	}
	dup2(fd, 1);
	close(fd);
	return (NULL);
}

int	redirection_checker(t_env *data)
{
	t_arg	*temp;

	temp = data->t_arg;
	if (temp->type == INPUT_RDR)
		input_rdr(data);
	else if (temp->type == OUTPUT_RDR)
		output_rdr(data);
	else if (temp->type == DOUBLE_INPUT_RDR)
		double_input_rdr(data);
	else if (temp->type == DOUBLE_OUTPUT_RDR)
		double_output_rdr(data);
	else
		return (1);
	return (0);
}
