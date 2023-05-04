/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:32:48 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/04 19:09:48 by mkarakul         ###   ########.fr       */
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
	char	**prompt;
	char	*line;
	char	*username;
	int		count;
	char	**envp;
	char	**parameter;
	char	**args;
	char	**command;
}				t_env;

typedef struct s_data
{
	t_env	*env;
}				t_data;

//utils
int		ft_strcmp(char *s1, char *s2);

// ms_utils
char	**ft_command_checker(char *str, t_env *data);
int		builtin(t_env *data, char **args, char **envp);
t_env	*parse_env(t_env *env, char **envp);
void	ft_execve(t_env *data, char **args, char **envp);

//builtin
void	ft_pwd(t_env *data, char **args);
void	*ft_addenv(t_env *data, char *name, char **args);
void	*ft_delenv(t_env *data, char *name, char **args);
void	*ft_getenv(t_env *data, char *name, char **args);
void	ft_env(t_env *data, char **args, char **envp);
char	*ft_strcpy(char *dest, const char *src);
void	parsing_line(t_env *data, char **envp);
void	all_free(t_env *data);

void	ft_echo(char **input);
void	ft_cd(char **execute);


#endif