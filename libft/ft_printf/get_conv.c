/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_conv.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 19:03:22 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:57:30 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_isconv(t_conv *conv, char c)
{
	ft_clear_isconv(conv);
	conv->f = c == 'f';
	conv->c = c == 'c';
	conv->s = c == 's';
	conv->p = c == 'p';
	conv->d = c == 'd';
	conv->i = c == 'i';
	conv->u = c == 'u';
	conv->x = c == 'x';
	conv->big_x = c == 'X';
	conv->n = c == 'n';
	conv->prc = c == '%';
	if (conv->i)
		conv->d = 1;
	if (conv->c || conv->s || conv->p || conv->d || conv->i || conv->u || \
		conv->x || conv->big_x || conv->n || conv->prc || conv->f)
		return (1);
	return (0);
}

void	ft_clear_isconv(t_conv *conv)
{
	conv->c = 0;
	conv->s = 0;
	conv->p = 0;
	conv->d = 0;
	conv->i = 0;
	conv->u = 0;
	conv->x = 0;
	conv->big_x = 0;
	conv->n = 0;
	conv->prc = 0;
	conv->f = 0;
}
