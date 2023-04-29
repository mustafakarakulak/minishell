all:
	gcc libft/libft.a parsing.c free.c builtin.c env_utils.c \
	checker.c minishell.c utils.c execve.c -lreadline -o minishell

clean:
	rm -rf minishell

fclean:
	$(clean)

git:
	git add .
	git status
	git commit -m "env and builtin created"
	git push