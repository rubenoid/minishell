/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:52:20 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:51:27 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tdst;
	char	*tsrc;

	tdst = (char *)dst;
	tsrc = (char *)src;
	i = 1;
	if (src < dst)
	{
		while (i <= len)
		{
			tdst[len - i] = tsrc[len - i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
