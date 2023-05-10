m = default commit message

all:
	gcc libft/libft.a srcs/parsing/parsing.c srcs/utils/free.c \
	srcs/builtin/builtin.c srcs/builtin/env_utils.c \
	srcs/check/checker.c srcs/minishell.c srcs/utils/utils.c \
	srcs/execute/execve.c srcs/builtin/ft_cd.c srcs/builtin/ft_echo.c \
	srcs/builtin/ft_export.c srcs/builtin/ft_unset.c srcs/redirection/redirection.c -lreadline -o minishell

clean:
	rm -rf libft/*.o

fclean:
	rm -rf minishell
    $(clean)

git:
	git add .
	git status
	git commit -m "$(m)"
	git push
