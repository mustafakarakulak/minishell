all:
	gcc libft/libft.a srcs/parsing/parsing.c srcs/utils/free.c srcs/builtin/builtin.c srcs/utils/env_utils.c \
	srcs/check/checker.c srcs/minishell.c srcs/utils/utils.c srcs/execute/execve.c -lreadline -o minishell

clean:
	rm -rf minishell

fclean:
	$(clean)

git:
	git add .
	git status
	git commit -m "env and builtin created"
	git push