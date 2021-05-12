/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dec_length.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:51:34 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:47:34 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dec_length(unsigned long long d)
{
	int	i;

	if (d == 0)
		return (1);
	i = 0;
	while (d)
	{
		i++;
		d = d / 10;
	}
	return (i);
}
