/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_ext.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 20:20:01 by anonymous     #+#    #+#                 */
/*   Updated: 2021/03/05 15:24:07 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static int	ft_check_quotes(char *s)
{
	size_t	i;
	int		d_quote;
	int		s_quote;

	d_quote = 0;
	s_quote = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' && !d_quote)
		{
			if (i == 0 || (i > 0 && s[i - 1] != '\\'))
				s_quote = !s_quote;
		}
		else if (s[i] == '"' && !s_quote)
		{
			if (i == 0 || (i > 0 && s[i - 1] != '\\'))
				d_quote = !d_quote;
		}
		i++;
	}
	return (s_quote || d_quote);
}

static int	ft_check_ends_pipe(char *s)
{
	size_t	i;

	if (ft_strlen(s) && !ft_check_quotes(s))
	{
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' && i != 0)
			i--;
		if (s[i] == '|')
			return (1);
	}
	return (0);
}

static int	ft_is_line_open(char **line)
{
	if (ft_check_quotes(*line))
	{
		*line = ft_strjoin_freefirst(*line, "\n");
		if (*line == NULL)
			exit(0);
		return (1);
	}
	if (ft_check_ends_pipe(*line))
		return (1);
	return (0);
}

int	get_next_line_ext(int fd, char **line)
{
	int		ret;
	char	*tmp;

	ret = 1;
	*line = ft_strdup("");
	while (ret > 0)
	{
		ret = get_next_line(fd, &tmp);
		if (ret < 0)
			exit(0);
		*line = ft_strjoin_freefirst(*line, tmp);
		free(tmp);
		if (*line == NULL)
			exit(0);
		if (!ft_is_line_open(line))
			break ;
		if (ret != 0)
			ft_printf("> ");
	}
	if (ret == 0 && ft_is_line_open(line))
	{
		ft_printf("%s: syntax error: unexpected end of file\n", SHELL);
		ret = 2;
	}
	return (ret);
}
