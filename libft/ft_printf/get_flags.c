/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_flags.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 23:26:57 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:58:18 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_clear_flags(t_flag *flag)
{
	flag->dot = 0;
	flag->dash = 0;
	flag->zero = 0;
	flag->sign = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->mod_el = 0;
	flag->mod_ha = 0;
	flag->width = 0;
	flag->prec = 0;
}

static int	ft_isflag(t_flag *flag, char c)
{
	if (c == '-')
		flag->dash = 1;
	if (c == '0')
		flag->zero = 1;
	if (c == '+')
		flag->sign = 1;
	if (c == ' ')
		flag->space = 1;
	if (c == '#')
		flag->hash = 1;
	if (c != '-' && c != '0' && c != '+' && c != ' ' && c != '#')
		return (0);
	return (1);
}

static int	ft_ismod(t_flag *flag, char c)
{
	if (c == 'l')
		flag->mod_el++;
	if (c == 'h')
		flag->mod_ha++;
	if (c != 'l' && c != 'h')
		return (0);
	return (1);
}

static int	get_width_or_prec(const char *format, va_list arg, int *i)
{
	int	nbr;

	nbr = 0;
	if (format[*i] == '*')
	{
		nbr = va_arg(arg, int);
		*i += 1;
	}
	else
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			nbr *= 10;
			nbr += format[*i] - '0';
			(*i)++;
		}
	}
	return (nbr);
}

int	get_flag_all(t_flag *flag, const char *format, va_list *arg, int i)
{
	ft_clear_flags(flag);
	i++;
	while (ft_isflag(flag, format[i]) && format[i] != '.')
		i++;
	if (ft_isdigit(format[i]))
		flag->width = get_width_or_prec(format, *arg, &i);
	else if (format[i] == '*')
	{
		flag->width = va_arg(*arg, int);
		i++;
	}
	if (format[i] == '.')
	{
		i++;
		flag->dot = 1;
		flag->prec = get_width_or_prec(format, *arg, &i);
	}
	while (ft_ismod(flag, format[i]))
		i++;
	return (i);
}
