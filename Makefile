all:
	gcc *.c libft/libft.a -lreadline -o minishell

clean:
	rm minishell

fclean:
	$(clean)

git:
	git add .
	git status
	git commit -m "second day"
	git push