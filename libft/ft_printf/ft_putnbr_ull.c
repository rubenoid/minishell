/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_ull.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:55:07 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/07/06 20:55:08 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr_ull(unsigned long long n)
{
	if (n > 9)
	{
		ft_putnbr_ull(n / 10);
		ft_putnbr_ull(n % 10);
	}
	else
		ft_putchar(n + '0');
}
