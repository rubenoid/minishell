/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validity_check.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 10:17:21 by anonymous     #+#    #+#                 */
/*   Updated: 2021/03/05 16:44:51 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static int	ft_val_return(char *token, t_shell *sh, int freeable, char *s)
{
	ft_printf("%s: syntax error near unexpected token `%s'\n", SHELL, token);
	if (freeable)
	{
		free(s);
		s = NULL;
	}
	free(sh->rval_malloced);
	sh->rval_malloced = ft_itoa((char) 2);
	return (1);
}

int	ft_check_semicolons(char *s)
{
	size_t	i;
	int		semicolon;

	i = 0;
	semicolon = 0;
	while (s[i])
	{
		if (s[i] == ';')
		{
			if (semicolon)
			{
				ft_printf("%s: syntax error near "
					"unexpected token `;'\n", SHELL);
				return (1);
			}
			semicolon = 1;
		}
		else
			semicolon = 0;
		i++;
	}
	return (0);
}

int	ft_validity_check(char *s, t_shell *sh, int freeable)
{
	size_t	i;

	i = 0;
	if (s == 0 || !*s)
		return (0);
	if (ft_check_semicolons(s))
	{
		if (freeable)
			free(s);
		s = NULL;
		return (1);
	}
	while (s[i] == ' ')
		i++;
	if (s[i] == ';')
		return (ft_val_return(";", sh, freeable, s));
	if (s[i] == '|')
		return (ft_val_return("|", sh, freeable, s));
	i = ft_strlen(s) - 1;
	while (i != 0 && s[i] == ' ')
		i--;
	if (s[i] == '<' || s[i] == '>')
		return (ft_val_return("newline", sh, freeable, s));
	return (0);
}
