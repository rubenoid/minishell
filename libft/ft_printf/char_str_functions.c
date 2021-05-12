/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_str_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 19:01:55 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/01/29 19:02:04 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr_chars(char *s, char c, int amount)
{
	ft_putstr(s);
	ft_putchar_amount(c, amount);
}

void	ft_putchars_str(char c, int amount, char *s)
{
	ft_putchar_amount(c, amount);
	ft_putstr(s);
}
