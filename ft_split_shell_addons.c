/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_shell_addons.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 20:03:24 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:22:05 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

int	ft_is_redorpipe(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

int	ft_find_begin(char *s, size_t *i)
{
	while (s[*i] == ' ' || s[*i] == '|')
		(*i)++;
	return (*i);
}

int	ft_find_end(char *s, size_t *i)
{
	int	s_quote;
	int	d_quote;

	s_quote = 0;
	d_quote = 0;
	while (s[*i] && ((s[*i]) != '|' || s_quote || d_quote))
	{
		if (s[*i] == '\'' && !d_quote)
			s_quote = !s_quote;
		if (s[*i] == '"' && !s_quote)
		{
			if (*i == 0)
				d_quote = !d_quote;
			else if (s[*i] != '\\')
				d_quote = !d_quote;
		}
		(*i)++;
	}
	return (*i);
}
