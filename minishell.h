/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:32:48 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/12 11:59:00 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parse/parse.h"
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
	t_arg	*t_arg;
	char	**prompt;
	char	*line;
	char	*username;
	int		count;
	char	**envp;
	char	**ex_path;
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
t_env	*parse_env(t_env *env, char **envp);
void	ft_execve(t_env *data);

//builtin
void	ft_pwd(t_env *data);
char	**ft_addenv(t_env *data);
void	*ft_delenv(t_env *data, int i, int env_c);
void	*ft_getenv(t_env *data, char *name, char **args);
void	ft_env(t_env *data);
void	parsing_line(t_env *data);
void	all_free(t_env *data);

void	ft_echo(t_env *data);
void	ft_cd(t_env *data);
void	ft_export(t_env *data);
void	ft_unset(t_env *data);

int		ft_redirection_control(t_env *data);
int		builtin(t_env *data);

int 	ft_parse(t_env *data);


#endif