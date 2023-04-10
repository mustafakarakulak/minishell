/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:26:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/10 19:10:20 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_screen(void)
{
	//const char	*clear_screen_asci = "\e[1;1H\e[2J";

	//write (STDOUT_FILENO, clear_screen_asci, 12);
	printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);
}

char *read_cat(char *str)
{
	int fd;
	char buf[1024];
	int n;

	n = 0;
	fd = open(str, O_RDONLY);
	while ((n = read(fd, buf, sizeof(buf))) > 0)
	{
		write(STDOUT_FILENO, buf, n);
	}
	write (1, "\0", 1");
	close(fd);
	return (str);
}