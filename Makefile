m = default commit message

NAME = minishell

LIBFT_S = cd libft && make

LIBFT_C = cd libft && make fclean

SRC = libft/libft.a srcs/utils/free.c \
	srcs/builtin/builtin.c srcs/builtin/env_utils.c \
	srcs/minishell.c srcs/utils/utils.c \
	srcs/execute/execve.c srcs/builtin/ft_cd.c srcs/builtin/ft_echo.c \
	srcs/builtin/ft_export.c srcs/builtin/ft_unset.c srcs/redirection/redirection.c \
	lexer/*.c parse/*.c srcs/command_line.c srcs/check.c

GCC = gcc

FLAG = -lreadline -o $(NAME)

all:
	$(LIBFT_S)
	$(GCC) $(SRC) $(FLAG)

clean:
	rm -rf $(NAME)

git:
	git add .
	git status
	git commit -m "$(m)"
	git push
