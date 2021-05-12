/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clean_quotes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 20:18:12 by anonymous     #+#    #+#                 */
/*   Updated: 2021/03/05 15:17:08 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static void	ft_set_vars(size_t *i, size_t *j, int *s_quote, int *d_quote)
{
	*i = 0;
	*j = 0;
	*s_quote = 0;
	*d_quote = 0;
}

static int	ft_set_quotes(const char *s, size_t *i, int *s_quote, int *d_quote)
{
	if (s[*i] == '\'' && !*d_quote)
	{
		*s_quote = !(*s_quote);
		*i += 1;
		return (1);
	}
	else if (s[*i] == '"' && !*s_quote)
	{
		if (*i == 0 || (s[*i - 1] != '\\'))
			*d_quote = !(*d_quote);
		*i += 1;
		return (1);
	}
	return (0);
}

static char	ft_copy_char(char *s, int s_quote, int d_quote, size_t *i)
{
	char	c;

	if (s[*i] == '\\' && s[*i + 1] == '"')
		return (s[*i + 1]);
	if (s[*i] == '\\' && !s_quote && !d_quote)
	{
		c = s[*i + 1];
		(*i)++;
		return (c);
	}
	if (s[*i] == '\\' && d_quote)
	{
		if (s[*i + 1] == '\\' || s[*i + 1] == '$')
			(*i)++;
		c = s[*i];
		return (c);
	}
	else
		return (s[*i]);
}

static char	*ft_remove_quotes(char *s)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	int		s_quote;
	int		d_quote;

	ft_set_vars(&i, &j, &s_quote, &d_quote);
	tmp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!tmp)
		exit(1);
	while (s[i])
	{
		if (ft_set_quotes(s, &i, &s_quote, &d_quote))
			continue ;
		else if (s_quote)
			tmp[j] = s[i];
		else if (s[i] != '"' && !s_quote)
			tmp[j] = ft_copy_char(s, s_quote, d_quote, &i);
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	ft_clean_quotes(t_commands *com)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (com->tokens[i])
	{
		j = 0;
		while (com->tokens[i][j])
		{
			tmp = ft_strdup(com->tokens[i][j]);
			if (tmp == NULL)
				exit(1);
			free(com->tokens[i][j]);
			com->tokens[i][j] = ft_remove_quotes(tmp);
			free(tmp);
			j++;
		}
		i++;
	}
}
