/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:32:48 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/10 18:29:17 by mkarakul         ###   ########.fr       */
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
# include <fcntl.h>

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
char	**ft_command_checker(char *str, t_env *data);
void	error_checker(t_env *data, char **env);
void	exec_shell(char **envp, t_env *data);

char *read_cat(char *str);
void clear_screen();

#endif