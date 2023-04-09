/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:32:48 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/09 14:11:15 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env
{
	char	*env;
	char	**log;
	int		log_i;
	char	*name;
	char	*value;
	char	*cmd;
	char	*param;
	char	**input;
	char 	*username;
	int		count;
}				t_env;

//utils
int		ft_strcmp(char *s1, char *s2);

// ms_utils
int		ft_command_checker(char *str, t_env *data);

#endif