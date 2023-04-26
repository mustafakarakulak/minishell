all:
	gcc builtin.c env_utils.c ft_strcpy.c checker.c minishell.c utils.c libft/libft.a ft_execve.c -lreadline -o minishell -g 

clean:
	rm -rf minishell

fclean:
	$(clean)

git:
	git add .
	git status
	git commit -m "env and builtin created"
	git push