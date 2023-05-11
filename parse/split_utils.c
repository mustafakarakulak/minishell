/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:46:10 by serif             #+#    #+#             */
/*   Updated: 2023/05/11 18:14:58 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"
void	*trim_quot(char *s)
{
	int	i;
	int	j;
	int	len;
	int l_quo;
	char	*trim_s;

	len = ft_strlen(s);
	l_quo = check_quotation(s);
	trim_s = malloc(sizeof(char ) * (len - l_quo + 1));
	if (!trim_s)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!is_quotation(&s[i]))
			trim_s[j++] = s[i++];
		else
			i++;
	}
	trim_s[j] = '\0';
	return (trim_s);
}