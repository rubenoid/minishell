/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 19:04:13 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 16:00:16 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_str_set_edges(t_flag *flag, char *s, int *s_len)
{
	if (flag->zero && flag->dash)
		flag->zero = 0;
	if (flag->width < 0)
	{
		flag->zero = 0;
		flag->dash = 1;
		flag->width *= -1;
	}
	*s_len = ft_strlen(s);
	if (flag->prec < 0)
		flag->prec = *s_len;
}

static void	ft_print_str_dash(t_flag *flag, char *s, int s_len)
{
	int	i;

	i = 0;
	if (flag->dot)
	{
		while (s[i] && i < flag->prec)
		{
			ft_putchar(s[i]);
			i++;
		}
		if (flag->prec < s_len)
			ft_putchar_amount(' ', flag->width - flag->prec);
		else
			ft_putchar_amount(' ', flag->width - s_len);
	}
	else
		ft_putstr_chars(s, ' ', flag->width - s_len);
}

static void	ft_print_str_dot(t_flag *flag, char *s, int s_len)
{
	int	i;

	i = 0;
	if (flag->prec < s_len)
		ft_putchar_amount(' ', flag->width - flag->prec);
	else
		ft_putchar_amount(' ', flag->width - s_len);
	while (s[i] && i < flag->prec)
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	print_str(t_flag *flag, char *s)
{
	int	s_len;

	if (s == NULL)
		s = "(null)";
	ft_str_set_edges(flag, s, &s_len);
	if (flag->dash)
		ft_print_str_dash(flag, s, s_len);
	else if (flag->dot)
		ft_print_str_dot(flag, s, s_len);
	else
		ft_putchars_str(' ', flag->width - s_len, s);
}
