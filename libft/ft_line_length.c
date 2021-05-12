/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_line_length.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:53:11 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:48:49 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_line_length(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
