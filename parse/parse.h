#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

enum character {
	WORD,
    INPUT_RDR,
    OUTPUT_RDR,
    DOUBLE_OUTPUT_RDR,
    DOUBLE_INPUT_RDR,
    PIPE,
    DOLLAR
};

enum loc_quot {
	none,
    head_end,
    midle
};

typedef struct s_arg {
    struct 			s_arg *next;
    char			*arg;
    enum character	type;
}					t_arg;


void	print_list(t_arg *lst);
int		is_redirection(char *s);
int		is_quotation(char *s);
int		is_pipe(char *s);
void	split_by_space(char *s, t_arg **line);
int		check_quotation(char *s);
void	p_lstadd_back(t_arg **lst, t_arg *new);
void	p_lstadd_front(t_arg **lst, t_arg *new);
int		p_lstsize(t_arg *lst);
t_arg	*p_lstnew(int type, char *s);
t_arg	*p_lstlast(t_arg *lst);
void	split_by_redirection(t_arg **prompt);
void	split_by_pipe(t_arg **prompt);
int		handle_character(t_arg **prompt, int (*checker)(char *));
int		identify_token(t_arg	**prompt);
#endif