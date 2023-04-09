all:
	gcc ms_utils.c minishell.c utils.c libft/libft.a -lreadline -o minishell -g 

clean:
	rm minishell

fclean:
	$(clean)

git:
	git add .
	git status
	git commit -m "second day"
	git push