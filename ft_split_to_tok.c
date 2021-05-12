/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_to_tok.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 20:05:16 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:23:03 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static size_t	ft_split_length(const char *s, char c)
{
	size_t	i;
	int		s_quote;
	int		d_quote;

	i = 0;
	s_quote = 0;
	d_quote = 0;
	if (ft_is_redorpipe(s[i]))
		return (ft_length_for_rorp(s, &i));
	while ((s[i] && s[i] != c && !ft_is_redorpipe(s[i]))
		|| (s[i] && (s_quote || d_quote)))
	{
		if (s[i] == '\'' && !d_quote)
			s_quote = !s_quote;
		if (s[i] == '\"' && !s_quote)
		{
			if (i == 0)
				d_quote = !d_quote;
			if (i > 0 && s[i - 1] != '\\')
				d_quote = !d_quote;
		}
		i++;
	}
	return (i);
}

static const char	*ft_next_split(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static size_t	ft_count_splits(char const *s, char c)
{
	size_t	n;

	n = 0;
	s = ft_next_split(s, c);
	while (*s)
	{
		s = s + ft_split_length(s, c);
		s = ft_next_split(s, c);
		n++;
	}
	return (n);
}

static void	ft_clean(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split_to_tok(const char *s, char c)
{
	char	**table;
	size_t	i;
	size_t	split_amount;

	if (!s)
		return (NULL);
	split_amount = ft_count_splits(s, c);
	table = (char **)malloc((split_amount + 1) * sizeof(char *));
	if (table == NULL)
		return (NULL);
	i = 0;
	while (i < split_amount)
	{
		s = ft_next_split(s, c);
		table[i] = ft_substr(s, 0, ft_split_length(s, c));
		if (table[i] == NULL)
		{
			ft_clean(table);
			return (NULL);
		}
		i++;
		s = s + ft_split_length(s, c);
	}
	table[split_amount] = NULL;
	return (table);
}
