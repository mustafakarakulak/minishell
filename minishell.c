/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/08 17:23:16 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_parse	*data;
	char	*line;

	data = (t_parse *)malloc(sizeof(t_parse));
	while (1)
	{
		line = readline("minishell$ ");
		add_history(line);
		write_history("/Users/mkarakul/Desktop/projemini/log/.bash_history");
		if (ft_strcmp(line, "exit"))
			break ;
		if(arg)
		printf("%s\n", ft_strdup(line));
	}
	return (0);
}
