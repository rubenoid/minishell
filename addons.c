/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addons.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 13:44:31 by okruitho      #+#    #+#                 */
/*   Updated: 2021/03/05 16:27:13 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

int	ft_strsjoin_copy(char *s, char *rval)
{
	int	x;

	x = 0;
	while (s && s[x] != 0)
	{
		rval[x] = s[x];
		x++;
	}
	return (x);
}

char	*ft_strsjoin(char *s1, char *s2, int seperator, int freeable)
{
	char	*rval;
	int		x;

	x = 0;
	if (s2 == 0 && seperator == 0)
		return (ft_strdup(s1));
	rval = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) \
		 + 1 + (seperator > 0)));
	if (rval == 0)
		return (0);
	x = ft_strsjoin_copy(s1, rval);
	if (seperator != 0 && x != 0)
	{
		rval[x] = seperator;
		x++;
	}
	x += ft_strsjoin_copy(s2, &rval[x]);
	rval[x] = 0;
	if (freeable == 1 || freeable == 3)
		free(s1);
	if (freeable == 2 || freeable == 3)
		free(s2);
	return (rval);
}

int	ft_iscempty(char *str, char c)
{
	int	x;

	x = 0;
	while (str && str[x] && str[x] != c)
	{
		if (str[x] != ' ')
			return (0);
		x++;
	}
	if (str[x] == c)
		return (1);
	return (0);
}

void	ft_set_rval(t_shell *sh)
{
	free(sh->rval_malloced);
	sh->rval_malloced = ft_itoa((char)sh->rval);
	sh->rval = 0;
}

int	ft_strclen(char *str, char c)
{
	int	x;

	x = 0;
	if (str == 0)
		return (0);
	while (str[x] != 0 && str[x] != c)
		x++;
	return (x);
}
