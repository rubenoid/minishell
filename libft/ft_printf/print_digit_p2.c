/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_digit_p2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 23:27:29 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/02/17 19:29:45 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_digit_set_edges(t_flag *flag, t_conv *conv,
			unsigned long long d)
{
	if (flag->width < 0)
	{
		flag->zero = 0;
		flag->dash = 1;
		flag->width *= -1;
	}
	if (conv->p || ((conv->x || conv->big_x) && flag->hash && d != 0))
		flag->width -= 2;
	if (flag->dot && flag->prec == 0)
		flag->prec = 1;
	if (flag->zero && flag->prec > 0)
		flag->zero = 0;
	if (flag->prec < 0)
		flag->prec = 1;
	if (flag->sign == -1 || flag->sign == 1 || flag->space)
		flag->width -= 1;
}

void	print_digit_other(t_flag *flag, t_conv *conv, int d_len,
			unsigned long long d)
{
	ft_putchar_amount(' ', flag->width - d_len);
	if (flag->sign == -1)
		ft_putchar('-');
	else if (flag->sign == 1)
		ft_putchar('+');
	else if (flag->space == 1)
		ft_putchar(' ');
	if (conv->p || (flag->hash && conv->x && d != 0))
		ft_putstr("0x");
	else if (flag->hash && conv->big_x && d != 0)
		ft_putstr("0X");
	if (conv->d || conv->u)
		ft_putnbr_ull(d);
	else
		ft_putnbr_hex(d, conv);
}
