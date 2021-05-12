/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 21:04:56 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:48:33 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_check_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	int		i;
	int		digit_amount;
	int		sign;
	char	*s;

	digit_amount = ft_count_digits(n);
	sign = ft_check_sign(n);
	if (sign == -1)
		digit_amount++;
	s = (char *)malloc((digit_amount + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = digit_amount - 1;
	if (n == 0)
		s[0] = '0';
	while (n && i >= 0)
	{
		s[i] = sign * (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (sign == -1)
		s[0] = '-';
	s[digit_amount] = '\0';
	return (s);
}
