/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   var_exhange.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 09:04:13 by anonymous     #+#    #+#                 */
/*   Updated: 2021/03/19 16:29:53 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static int	ft_variable_len(char *str)
{
	int	x;

	x = 0;
	while (ft_isalnum(str[x]) || str[x] == '?' || str[x] == '_')
		x++;
	return (x);
}

/*
** ft_varlen counts a " as double to make space for \ character
*/

static int	ft_varlen(char *s)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] == '"')
			a++;
		i++;
		a++;
	}
	return (a);
}

static char	*ft_enclose_with_quotes(char *str)
{
	int		i;
	int		length;
	char	*str_quotes;

	i = 0;
	length = ft_varlen(str);
	str_quotes = malloc((length + 3) * sizeof(char));
	if (!str_quotes)
		return (0);
	str_quotes[0] = '"';
	while (str[i])
	{
		if (str[i] == '"')
			str_quotes[i] = '\\';
		str_quotes[i + 1] = str[i];
		i++;
	}
	str_quotes[i + 1] = '"';
	str_quotes[i + 2] = 0;
	free(str);
	return (str_quotes);
}

static char	*ft_get_var(t_shell *sh, char *str)
{
	char	*s;
	int		len;

	s = ft_strdup(ft_export_findn(sh, str + 1, ft_variable_len(str + 1)));
	if (!s)
		return (0);
	len = ft_strlen(str);
	if (len > 2 && !ft_strncmp(str, "$?", 2) && str[2] != '\"')
		s = ft_strjoin_freefirst(s, str + 2);
	if (!s)
		return (0);
	s = ft_enclose_with_quotes(s);
	if (!s)
		exit(1);
	return (s);
}

char	*ft_exchanger(t_shell *sh, char *str)
{
	int		x;
	char	*rval;
	int		quotes;

	x = 0;
	rval = 0;
	quotes = 0;
	while (str[x] != 0)
	{
		if (str[x] == '\'')
			quotes = !quotes;
		if (((x == 0 && str[x] == '$') \
		 || (x > 0 && str[x] == '$' && str[x - 1] != '\\')) && !quotes)
		{
			rval = ft_strsjoin(ft_substr(str, 0, x), ft_get_var(sh, &str[x]) \
			, 0, 3);
			rval = ft_strsjoin(rval, &str[x + ft_variable_len(&str[x + 1]) + 1] \
			, 0, 1);
			free(str);
			return (ft_exchanger(sh, rval));
		}
		x++;
	}
	return (str);
}
