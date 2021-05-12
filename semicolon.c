/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   semicolon.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 11:34:10 by anonymous     #+#    #+#                 */
/*   Updated: 2021/03/05 15:27:04 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

int	ft_find_semicolon(char *s)
{
	int	dquote;
	int	squote;
	int	x;

	dquote = 0;
	squote = 0;
	x = 0;
	while (s[x] != 0)
	{
		if (s[x] == '"')
			dquote = !dquote;
		else if (s[x] == '\'')
			squote = !squote;
		else if (s[x] == ';' && dquote == 0 && squote == 0)
			return (x);
		x++;
	}
	return (x);
}
