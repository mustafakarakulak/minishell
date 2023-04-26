/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:32:48 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/26 15:24:35 by mkarakul         ###   ########.fr       */
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
# include <dirent.h>

typedef struct s_env
{
	char	**line;
	char	*username;
	int		count;
	int		key;
	int		value;
	char	*key_str;
	char	*value_str;
	char	**envp;
}				t_env;

typedef struct s_data
{
	t_env	*env;
}				t_data;

//utils
int		ft_strcmp(char *s1, char *s2);

// ms_utils
char	**ft_command_checker(char *str, t_env *data);
void	control_shell(char **envp, t_env *data);

int		builtin(t_env *data, char **args, char **envp);
t_env	*parse_env(t_env *env, char **envp);
void	ft_execve(t_env *data, char **args, char **envp);

#endif