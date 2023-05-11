
#include "../minishell.h"
#include "parse.h"

int	is_quotation(char *s)
{
	if (*s == '\"' || *s == '\'')
		return (1);
	return (0);
}

int is_space(char s)
{
	if (s == 32)
		return (1);
	return (0);
}

void	split_line(char *s, t_arg *line)
{
	int	i;
	int	st;
	int	len;
	int	quo;

	i = -1;
	st = 0;
	len = 1;
	quo = 0;
	while (++i || 1)
	{
		if (is_quotation(&s[i]) && len++)
			while (!is_quotation(&s[++i]) && s[i])
				len++;
		if (is_space(s[i]) || !s[i])
		{
			if (len != 1)
				p_lstadd_back(&line, p_lstnew(0, ft_substr(s, st, len - 1)));
			st = i + 1;
			len = 0;
		}
		if (!s[i])
			break;
		len++;
	}
	free(s);
}

void split_by_space(char *s, t_arg **line)
{
	int	i;
	int	len;
	int	l_quotation;
	char	*prompt;
	t_arg	*line_f;

	l_quotation = check_quotation(s);
	s = ft_strtrim(s, " ");
	split_line(s, *line);
	line_f = *line;
	*line = (*line)->next;
	free(line_f);
}