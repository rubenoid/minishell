/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nbr_length_ull.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 19:03:51 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:58:37 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_len_hex(unsigned long long d)
{
	int	i;

	if (d == 0)
		return (1);
	i = 0;
	while (d)
	{
		i++;
		d = d / 16;
	}
	return (i);
}

int	ft_len_dec(unsigned long long d)
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
