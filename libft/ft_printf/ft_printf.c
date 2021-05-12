/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 19:03:03 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:56:35 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			g_cnt = 0;
int			g_error_check = 0;

void	ft_putchar(int c)
{
	if (g_error_check == -1)
		return ;
	if (write(1, &c, 1) == -1)
		g_error_check = -1;
	g_cnt++;
}

static int	ret_global(void)
{
	int	a;

	if (g_error_check == -1)
		a = g_error_check;
	else
		a = g_cnt;
	g_cnt = 0;
	g_error_check = 0;
	return (a);
}

static void	ft_conv_n(va_list *arg, t_flag *flag)
{
	if (flag->mod_ha == 1)
		*(va_arg(*arg, unsigned char *)) = g_cnt;
	if (flag->mod_ha == 2)
		*(va_arg(*arg, unsigned short *)) = g_cnt;
	if (flag->mod_el == 1)
		*(va_arg(*arg, unsigned long *)) = g_cnt;
	if (flag->mod_el == 2)
		*(va_arg(*arg, unsigned long long *)) = g_cnt;
	else
		*(va_arg(*arg, int *)) = g_cnt;
}

static void	ft_conversions(va_list *arg, t_flag *flag, t_conv *conv)
{
	if (conv->prc)
		print_char(flag, '%');
	else if (conv->c)
		ft_conv_c(arg, flag);
	else if (conv->d)
		ft_conv_d(arg, flag, conv);
	else if (conv->x || conv->big_x || conv->u || conv->p)
		ft_conv_xup(arg, flag, conv);
	else if (conv->s)
		ft_conv_s(arg, flag);
	else if (conv->n)
		ft_conv_n(arg, flag);
	ft_clear_isconv(conv);
	ft_clear_flags(flag);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_conv		conv;
	t_flag		flag;
	int			i;
	int			f_len;

	i = 0;
	va_start(arg, format);
	f_len = ft_strlen(format);
	while (format[i] && i < f_len)
	{
		if (g_error_check == -1)
			return (ret_global());
		if (format[i] != '%')
			ft_putchar(format[i]);
		if (format[i] == '%')
		{
			i = get_flag_all(&flag, format, &arg, i);
			if (ft_isconv(&conv, format[i]))
				ft_conversions(&arg, &flag, &conv);
		}
		i++;
	}
	va_end(arg);
	return (ret_global());
}
