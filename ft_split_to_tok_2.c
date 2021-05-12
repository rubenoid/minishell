/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_to_tok_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 20:09:10 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/11/29 20:09:29 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

int	ft_length_for_rorp(const char *s, size_t *i)
{
	if (ft_is_redorpipe(s[*i]))
	{
		(*i)++;
		while (ft_is_redorpipe(s[*i]))
			(*i)++;
		return (*i);
	}
	return (*i);
}
