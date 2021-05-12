/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 19:35:45 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 16:00:42 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen && s[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *d, const char *s, size_t maxlen)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(s);
	dlen = ft_strnlen(d, maxlen);
	ft_strlcpy(d + dlen, s, maxlen - dlen);
	return (dlen + slen);
}
