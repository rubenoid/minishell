/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_digit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 19:04:07 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:59:59 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_digit_dash(t_flag *flag, t_conv *conv, int d_len,
				unsigned long long d)
{
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
	ft_putchar_amount('0', flag->prec - d_len);
	if (conv->d || conv->u)
		ft_putnbr_ull(d);
	else
		ft_putnbr_hex(d, conv);
	if (flag->prec < d_len)
		ft_putchar_amount(' ', flag->width - d_len);
	else
		ft_putchar_amount(' ', flag->width - flag->prec);
}

static void	print_digit_dot(t_flag *flag, t_conv *conv, int d_len,
				unsigned long long d)
{
	if (flag->width > flag->prec && flag->prec >= d_len)
		ft_putchar_amount(' ', flag->width - flag->prec);
	else if (d_len > flag->prec)
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
	ft_putchar_amount('0', flag->prec - d_len);
	if (conv->d || conv->u)
		ft_putnbr_ull(d);
	else
		ft_putnbr_hex(d, conv);
}

static void	print_digit_zero(t_flag *flag, t_conv *conv, int d_len,
			unsigned long long d)
{
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
	ft_putchar_amount('0', flag->width - d_len);
	if (conv->d || conv->u)
		ft_putnbr_ull(d);
	else
		ft_putnbr_hex(d, conv);
}

static void	print_digit_prec_zero(t_flag *flag, t_conv *conv)
{
	if (conv->p)
	{
		if (flag->width < 0 || flag->dash)
			ft_putstr_chars("0x", ' ', ft_abs(flag->width) - 2);
		else
			ft_putchars_str(' ', flag->width - 2, "0x");
	}
	else
	{
		if (flag->sign == 1 && flag->dash)
			ft_putstr_chars("+", ' ', flag->width - 1);
		else if (flag->sign == 1)
			ft_putchars_str(' ', flag->width - 1, "+");
		else
			ft_putchar_amount(' ', ft_abs(flag->width));
	}
}

void	print_digit(t_flag *flag, t_conv *conv, unsigned long long d)
{
	int	d_len;

	if (flag->dot && flag->prec == 0 && d == 0)
	{
		print_digit_prec_zero(flag, conv);
		return ;
	}
	if (conv->d || conv->u)
		d_len = ft_len_dec(d);
	else
		d_len = ft_len_hex(d);
	print_digit_set_edges(flag, conv, d);
	if (flag->dash)
		print_digit_dash(flag, conv, d_len, d);
	else if (flag->zero)
		print_digit_zero(flag, conv, d_len, d);
	else if (flag->dot)
		print_digit_dot(flag, conv, d_len, d);
	else
		print_digit_other(flag, conv, d_len, d);
}
