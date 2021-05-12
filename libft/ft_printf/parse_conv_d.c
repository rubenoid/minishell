/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_conv_d.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 19:03:58 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:59:09 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_conv_d_el(va_list *arg, t_flag *flag, t_conv *conv)
{
	long long			tmp;
	unsigned long long	hey;

	if (flag->mod_el == 1)
		tmp = va_arg(*arg, long);
	else
		tmp = va_arg(*arg, long long);
	if (tmp < 0)
	{
		hey = tmp * -1;
		flag->sign = -1;
		print_digit(flag, conv, hey);
	}
	else
		print_digit(flag, conv, tmp);
}

static void	ft_conv_d_ha(va_list *arg, t_flag *flag, t_conv *conv)
{
	long long	tmp;

	if (flag->mod_ha == 1)
	{
		tmp = (short)va_arg(*arg, int);
		if (tmp < 0)
		{
			flag->sign = -1;
			tmp *= -1;
		}
		print_digit(flag, conv, tmp);
	}
	else
	{
		tmp = (signed char)va_arg(*arg, int);
		if (tmp < 0)
		{
			flag->sign = -1;
			tmp *= -1;
		}
		print_digit(flag, conv, tmp);
	}
}

void	ft_conv_d(va_list *arg, t_flag *flag, t_conv *conv)
{
	long long	tmp;

	if (flag->mod_el)
		ft_conv_d_el(arg, flag, conv);
	else if (flag->mod_ha)
		ft_conv_d_ha(arg, flag, conv);
	else
	{
		tmp = (va_arg(*arg, int));
		if (tmp < 0)
		{
			flag->sign = -1;
			tmp *= -1;
		}
		print_digit(flag, conv, tmp);
	}
}
