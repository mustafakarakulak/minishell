/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:20:57 by spalta            #+#    #+#             */
/*   Updated: 2023/05/12 11:50:20 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

void	print_list(t_arg *lst)
{
	while (lst->next)
	{
		printf ("%s\n", lst->arg);
		lst = lst->next;
	}
	printf ("%s\n", lst->arg);
}

int check_quotation(char *s)
{
	char	handle;
	int		i;
	int		len;

	handle = '\"';
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == handle)
			len++;
		i++;
	}
	if (len % 2)
		exit(1);
	else
		return (len);
}
void	tokenizer(t_arg **prompt, t_env **data)
{
	split_by_space((*data)->line, prompt);
	split_by_redirection(prompt);
	split_by_pipe(prompt);
}

int ft_parse(t_env *data)
{
	t_arg	*line;


	line = ft_calloc(1, sizeof(t_arg));
	tokenizer(&line, &data);
	identify_token(&line);
	data->t_arg = line;
	return (1);
}
