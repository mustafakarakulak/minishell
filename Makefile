all:
	gcc ms_utils.c minishell.c utils.c libft/libft.a term_utils.c ft_execve.c -lreadline -o minishell -g 

clean:
	rm minishell

fclean:
	$(clean)

git:
	git add .
	git status
	git commit -m "4 th day"
	git push