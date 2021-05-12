/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_shell.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 20:56:03 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:21:38 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static void	ft_do_count(char *line, int s_quote, int d_quote, t_commands *com)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' && !d_quote)
			s_quote = !s_quote;
		if (line[i] == '\"' && !s_quote)
		{
			if (i == 0)
				d_quote = !d_quote;
			if (i > 0 && line[i - 1] != '\\')
				d_quote = !d_quote;
		}
		if ((!s_quote && ft_is_redorpipe(line[i])) || \
			(!d_quote && ft_is_redorpipe(line[i])))
		{
			if (line[i] == '>' && line[i + 1] == '>')
				i++;
			com->amount_commands++;
			com->amount_redirects++;
			i++;
		}
		i++;
	}
}

static void	ft_amount_com_red(char *line, t_commands *com)
{
	int	d_quote;
	int	s_quote;

	d_quote = 0;
	s_quote = 0;
	com->amount_commands = 1;
	com->amount_redirects = 0;
	ft_do_count(line, d_quote, s_quote, com);
}

static void	ft_alloc_tokens_redirects(char *line, t_commands *com)
{
	size_t	i;

	ft_amount_com_red(line, com);
	com->tokens = (char ***)malloc((com->amount_commands + 1) * sizeof(char *));
	com->redirect = malloc((com->amount_commands + 1) * sizeof(t_redirect *));
	i = 0;
	while (i < (size_t)com->amount_redirects)
	{
		com->redirect[i] = ft_calloc(2, sizeof(t_redirect));
		i++;
	}
	com->redirect[i] = 0;
}

static void	ft_fill_tokens(char *line, t_commands *com)
{
	size_t	i;
	size_t	j;
	int		begin;
	int		end;
	char	*substring;

	i = 0;
	j = 0;
	while (i < (size_t)com->amount_commands)
	{
		begin = ft_find_begin(line, &j);
		end = ft_find_end(line, &j);
		substring = ft_substr(line, begin, end - begin);
		if (!substring)
			exit(1);
		com->tokens[i] = ft_split_to_tok(substring, ' ');
		i++;
		free(substring);
	}
	com->tokens[i] = NULL;
}

void	ft_split_shell(char *line, t_commands *com)
{
	int	i;

	ft_alloc_tokens_redirects(line, com);
	ft_fill_tokens(line, com);
	i = 0;
	while (com->tokens[i] != 0 && com->tokens[i][0])
		i++;
	com->amount_commands = i;
}
