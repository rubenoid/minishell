/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 19:04:04 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/01/29 19:04:06 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_char(t_flag *flag, int c)
{
	if (flag->zero && flag->dash)
		flag->zero = 0;
	if (flag->width < 0)
	{
		flag->zero = 0;
		flag->dash = 1;
		flag->width *= -1;
	}
	if (flag->zero)
	{
		ft_putchar_amount('0', flag->width - 1);
		ft_putchar(c);
	}
	else if (flag->dash)
	{
		ft_putchar(c);
		ft_putchar_amount(' ', flag->width - 1);
	}
	else
	{
		ft_putchar_amount(' ', flag->width - 1);
		ft_putchar(c);
	}
}
