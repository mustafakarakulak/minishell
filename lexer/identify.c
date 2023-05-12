/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:35:14 by serif             #+#    #+#             */
/*   Updated: 2023/05/12 11:50:15 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"

int	contains_dollars(char *s)
{
	int i;

	i = -1;
	if (!s || !*s)
		return (0);
	while (s[++i])
		if (s[i] == '$')
			return (1);
	return (0);
}

int	initilaze_metacharacter(t_arg	*node)
{
	int	len;

	len = ft_strlen(node->arg);
	if (len == 1)
		if (*node->arg == '<')
			node->type = INPUT_RDR;
		else if (*node->arg == '>')
			node->type = OUTPUT_RDR;
		else if (*node->arg == '|')
			node->type = PIPE;
	if (len == 2)
		if (*node->arg == '<' && *(node->arg + 1) == '<')
			node->type = DOUBLE_INPUT_RDR;
		else if (*node->arg == '>' && *(node->arg + 1) == '>')
			node->type = DOUBLE_OUTPUT_RDR;
		else
		{
			printf ("redirection error >< ?\n");
			exit (1);
		}
}

int	identify_token(t_arg	**prompt)
{
	t_arg	*iter;

	iter = *prompt;
	while (iter)
	{
		if (contains_dollars(iter->arg))
		{
			iter->type = DOLLAR;
			if (iter->next)
				iter = iter->next;
		}
		else if (is_redirection(iter->arg) || is_pipe(iter->arg))
			initilaze_metacharacter(iter);
		else
			iter->type = WORD;
		if (iter->next)
			iter = iter->next;
		else
			break;
	}
}