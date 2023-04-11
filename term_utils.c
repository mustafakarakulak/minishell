/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:26:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/11 14:54:35 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_screen(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);
}

char	*read_cat(char *str)
{
	int		fd;
	char	buf[1024];
	int		n;

	n = 0;
	fd = open(str, O_RDONLY);
	while ((n = read(fd, buf, sizeof(buf))) > 0)
	{
		write(STDOUT_FILENO, buf, n);
	}
	close(fd);
	write(1, "\n", 1);
	return (str);
}
