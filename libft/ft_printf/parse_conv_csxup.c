/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_conv_csxup.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 19:20:55 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:58:48 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_conv_c(va_list *arg, t_flag *flag)
{
	int	c;

	c = va_arg(*arg, int);
	print_char(flag, c);
}

void	ft_conv_s(va_list *arg, t_flag *flag)
{
	char	*str;

	str = va_arg(*arg, char *);
	print_str(flag, str);
}

void	ft_conv_xup(va_list *arg, t_flag *flag, t_conv *conv)
{
	if (flag->mod_el == 1)
		print_digit(flag, conv, va_arg(*arg, unsigned long));
	else if (flag->mod_el == 2)
		print_digit(flag, conv, va_arg(*arg, unsigned long long));
	else if (flag->mod_ha == 1)
		print_digit(flag, conv, (unsigned short)va_arg(*arg, int));
	else if (flag->mod_ha == 2)
		print_digit(flag, conv, (unsigned char)va_arg(*arg, int));
	else if (!conv->p)
		print_digit(flag, conv, va_arg(*arg, unsigned int));
	else
		print_digit(flag, conv, va_arg(*arg, unsigned long));
}
