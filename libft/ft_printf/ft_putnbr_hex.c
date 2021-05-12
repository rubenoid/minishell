/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:54:55 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:57:00 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr_hex(unsigned long n, t_conv *conv)
{
	if (n > 15)
	{
		ft_putnbr_hex(n / 16, conv);
		ft_putnbr_hex(n % 16, conv);
	}
	else
	{
		if (n > 9)
		{
			if (conv->big_x)
				ft_putchar(n + 55);
			else
				ft_putchar(n + 87);
		}
		else
			ft_putchar(n + '0');
	}
}
