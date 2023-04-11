/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:32:48 by mkarakul          #+#    #+#             */
/*   Updated: 2023/04/11 18:10:09 by mkarakul         ###   ########.fr       */
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
	char	**input;
	char	*username;
	int		count;
}				t_env;

//utils
int		ft_strcmp(char *s1, char *s2);

// ms_utils
char	**ft_command_checker(char *str, t_env *data);
void	control_shell(char **envp, t_env *data);

char	*read_cat(char *str);
void	clear_screen(void);

t_env	*parse_env(t_env *env, char **envp);
void	ft_execve(t_env *data, char **args, char **envp);

#endif